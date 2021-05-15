#include <algorithm>
#include "numword.hpp"

namespace num2word{  

static const char* const ones[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
static const char* const tenTwnty[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
static const char* const tens[] = {"twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};

static const std::string hundred = " hundred ";
static const std::string thousand = " thousand ";
static const std::string million = " million ";
static const std::string billion = " billion ";
static const std::string trillion = " trillion ";

// Intentionally I added these declaratios here to prevent none readable code in the header file 
// Theses declared varibles are only needed in this source file

// size of input_
static uint32_t size_;
// the resulted answer in string format
static  std::string ans; 
// the program reads in three digit steps 
static uint8_t offset;
// we need a copy from the variable passed to the class in string format
static std::string cpy;
// this is needed to know which digit power we have, for example to know if it is hundred thousand, hundred million or only hundred
static std::string dgtVal;

template<typename T>
numword<T>::numword(T in) : input_(std::to_string(in)){}

template<>
numword<const char*>::numword(const char* in)  : input_(in) {}

template<>
numword<std::string>::numword(std::string in)  : input_(in) {}

template<>
numword<char*>::numword(char* in)  : input_(in) {}

std::string oneDgt(std::string str) {
    return ones[str[0] - '0'];
}

std::string twoDgt(std::string str) {
    if(str[0] == '1') return tenTwnty[str[1] - '0'];
    else if(str[0] == '0' && str[1] == '0') return ""; 
    else if(str[0] == '0') {return oneDgt(str.substr(1,1));} 
    else if(str[1] == '0') return tens[str[0] - '0' -2];     
    else return std::string(tens[str[0] - '0' -2]) + '-' + std::string(ones[str[1] - '0']);
};

std::string ThrDgt(std::string str) {
    switch (str.size())
    {
    case 3:
        if(!(str[0]-'0')) {return twoDgt(str.substr(1,2));}
        else if(!(str[1]-'0') && !(str[2]-'0')) return ones[str[0]-'0'] + hundred;
        else return ones[str[0]-'0'] + hundred + twoDgt(str.substr(1,2));
    case 2:
        return twoDgt(str);
    case 1:
        return oneDgt(str);
    }
    throw num2wordExc("Exception: too long string.");
}

unsigned getOfst(){
    offset = size_ % 3;
    if(!offset) offset = 3;
    return offset;
}

std::string setDgtVal(){
    if(size_<=3 && size_>=0) dgtVal = "";
    else if(size_>3 && size_<=6) dgtVal = thousand;
    else if(size_>6 && size_<=9) dgtVal = million;
    else if(size_>9 && size_<=12) dgtVal = billion;
    else if(size_>12 && size_<=15) dgtVal = trillion;
    return dgtVal;
}

void clnVal(){
    bool prev = false;
    // remove duplicated spaces
    auto pend = remove_if(ans.begin(),ans.end(),[&prev](char c) -> bool {
    if ((c == ' ' && prev) || (c == '-' && prev)) return true;
    prev = (c == ' ');
    return false;
    });
    // remove carbage values from the string
    for(auto it = pend;it != ans.end();++it) {*it = ' ';}
}

// primary methode which parses the nums and converts them to their equivalent strings
template<typename T>
bool numword<T>::parseNum() {
    ans = "";
    size_ = input_.size();
    cpy = input_;
    if(!is_digits()) throw num2wordExc("Exception: invalid input.. please check your string");
    if(size_>15) throw num2wordExc("Exception: too long string. maximum supported digits are 15");
    while (true)
    {       
        if(size_<=3) {
            ans += ThrDgt(input_);
            break;
        }
        else if(!(size_ % 3) && input_[0] == '0' && input_[1] == '0' && input_[2] == '0') {
            ans += ThrDgt(input_.substr(3,size_-3));
        }         
        else {
            ans += ThrDgt(input_.substr(0, getOfst())) + setDgtVal();
        }

        cpy = cpy.substr(offset, cpy.size()-offset);
        input_ = cpy.substr(0, 3);
        size_ = cpy.size();
    } 
    clnVal();
    return true;      
}

template<typename T>
bool numword<T>::is_digits() const
{
    return std::all_of(input_.begin(), input_.end(), isdigit); 
}

template<typename T>
std::string numword<T>::getNum() const{
    return ans;
}

template<typename T>
std::ostream& operator<<(std::ostream& o, const numword<T>& n){
    return o << n.getNum(); 
}
}

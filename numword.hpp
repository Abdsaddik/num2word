#ifndef _NUMWORD_H
#define _NUMWORD_H

#include<iostream>
#include"num2wordExc.hpp" 

namespace num2word{

class  numword
{
private:
    // variable passsed to the class in string format
    std::string input_; 
    // check if all string digits are only numbers from 0 to 9
    bool is_digits() const;  
    
public:
     numword(std::string in);
     numword(const char* in);
     numword(uint64_t in = 0);
     bool parseNum();
     std::string getNum() const;
    ~ numword() = default;
};

std::ostream& operator<<(std::ostream& o, const numword& n);

}

#endif
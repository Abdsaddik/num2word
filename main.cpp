#include "numword.hpp"
#include<cstring>

using namespace num2word;

int main(){
    
    try
    {
        char* num = new char[50];
        strcpy(num, "1000");
        // pointer to a string of char's is accepted
        numword<char*> word(num);
        word.parseNum();
        std::cout << "num is: " << word << std::endl;
        /*example how to use default constructor, default value is zero*/
        numword<> defaultObj;
        defaultObj.parseNum();
        std::cout << "num is: " << defaultObj << std::endl;
        /* pass the number as const char* */
        numword<const char*> word1("999999999999999");
        word1.parseNum();
        /* the string answer has the value of the given number in string format*/
        // std::string answer = word1.getNum(); 
        /* print the result*/
        // std::cout << "answer = " << answer << std::endl;
        /* print the same result in another way*/
        std::cout << "num is: " << word1 << std::endl;;
        /* pass the number as int */
        numword<int> word2(100000);
        word2.parseNum();
        std::cout << "num is: " << word2 << std::endl;
        /* pass the number as std::string */
        std::string str = "1100100001";
        numword<std::string> obj3(str);
        obj3.parseNum();
        std::cout << "num is: " << obj3 << std::endl; 
    }
    
    catch(num2wordExc& e)
    {
        std::cout << e.what() << '\n';
    }
  
    return 0;
}

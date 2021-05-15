#ifndef _NUMWORD_H
#define _NUMWORD_H

#include<iostream>
#include"num2wordExc.hpp" 

namespace num2word{

template<typename T = int>
class  numword
{
private:
    // variable passsed to the class in string format
    std::string input_; 
    // check if all string digits are only numbers from 0 to 9
    bool is_digits() const;  
    
public:
     explicit numword(T in = 0);
     
     bool parseNum();
     std::string getNum() const;
    ~ numword() = default;
};

template<typename T>
std::ostream& operator<<(std::ostream& o, const numword<T>& n);

}
#include"numword.inl"

#endif
#ifndef NUM2WORDEXC_HPP
#define NUM2WORDEXC_HPP

class num2wordExc{
    private:
    const char* msg;
    num2wordExc(){}

    public:
    explicit num2wordExc(const char* s) throw() : msg{s}{}
    const char* what() throw() {return msg;} 
};


#endif
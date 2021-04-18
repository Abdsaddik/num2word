# num2word
This program converts an integer to its equivalent string value. For example **1** is converted to **one** and so on. Maximum allowed number is 15 digit number. Negative numbers are not supported. 
The number can be passed as normal integer or even long long int, standard string **std::string** or as c-string "const char*".  
## Example
the number 3,548,975,114 is outputed as follows in terminal 
```
three billion five hundred fourty-eight million nine hundred seventy-five thousand one hundred fourteen
```
I gave several examples in main.cpp to illustrate how to work with the class numword.
## Code Compilation and running
Once you have g++ compiler running in your machine, type the following line in the terminal:  
```
g++ -Wall -std=c++11 -o numword *.cpp && numword
```
typical terminal output should be as the following:
```
num is: zero
num is: nine hundred ninety-nine trillion nine hundred ninety-nine billion nine hundred ninety-nine million nine hundred ninety-nine thousand nine hundred ninety-nine
num is: one hundred thousand
num is: one billion one hundred million one hundred thousand one
```
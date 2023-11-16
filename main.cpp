#include <iostream>
#include "Five.hpp"


int main()
{
    Five num1 = {'2','0','0','1'};
    Five num2("104");

    Five r = num1 - num2;
    bool res1 = num2 <= num1;
    bool res2 = num2 >= num1;
    bool res3 = num2 == num1;

    unsigned char* v2 = num2.get_value();
    unsigned char* v1 = num1.get_value();
    unsigned char* r_v = r.get_value();
    size_t s2 = num2.get_size();
    size_t s1 = num1.get_size();
    
    std::cout << "num1 value|size  " << v1 << '|' << s1 << std::endl;
    std::cout << "num2 value|size  " << v2 << '|' << s2 << std::endl;
    std::cout << "Разность " << r_v << std::endl;
    std::cout << "bool <= " << res1 << std::endl;
    std::cout << "bool >= " << res2 << std::endl;
    std::cout << "bool == " << res3 << std::endl;

    return 0;
}
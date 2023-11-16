#include <iostream>
#include "Five.hpp"


int main()
{
    Five num = {'2','0','0','1'};
    Five nnn("104");
    Five r = num - nnn;
    bool res = nnn <= num;
   // nnn = num;
    unsigned char* n = nnn.get_value();
    unsigned char* nn = num.get_value();
    unsigned char* rn = r.get_value();
    size_t s = nnn.get_size();
    size_t sn = num.get_size();
    std::cout << n << ' ' << nn << '\n' << s << ' ' << sn << '\n' << res << '\n' << rn << std::endl;
    return 0;
}
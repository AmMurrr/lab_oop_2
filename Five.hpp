#pragma once

#include <iostream>
#include <string>

class Five {

public:
    Five();
    Five(const size_t &n, unsigned char t = 0);
    Five(const std::initializer_list< unsigned char> &t);
    Five(const std::string &t);
    Five(const Five &other);
    Five(Five &&other) noexcept;
    virtual ~Five() noexcept;


    size_t get_size();
    unsigned char* get_value();

    bool operator>(const Five &other);
    bool operator<(const Five &other);
    bool operator==(const Five &other);
    bool operator!=(const Five &other);
    bool operator>=(const Five &other);
    bool operator<=(const Five &other);
    Five operator+(const Five &other);
    Five operator-(const Five &other);
    Five operator=(const Five &other);
    

private:
    
    unsigned char* _five;
    size_t _size;

    bool validation(const std::string &t);
    void resize(signed char shift);

};
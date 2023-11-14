#pragma once

#include <iostream>
#include <string>
#include <exception>

class Five {
    public:
        Five();
        Five(const size_t &n, unsigned char t = 0);
        Five(const std::initializer_list< unsigned char> &t);
        Five(const std::string &t);

        Five(const Five& other);
        Five(Five&& other) noexcept;
        virtual ~Five() noexcept;

        bool operator ==( const Five& other);
        bool operator >(const Five& other);
        bool operator <(const Five& other);
        bool operator >=(const Five& other);
        bool operator <=(const Five& other);
        bool operator !=(const Five& other);

        Five operator +(const Five& other);
        Five operator -(const Five& other);
        Five /*&*/operator =(const Five& other);




};
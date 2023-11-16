#include "Five.hpp"

Five::Five() {
    _size = 0;
    _five = new unsigned char[0]{};
}

Five::Five(const size_t &n, unsigned char t) {
    std::string t_s(1, t);
    validation(t_s);
    _size = n;
    _five = new unsigned char[n]{};
    for(int i = 0; i < n; i++)
        _five[i] = t;
    
}

Five::Five(const std::initializer_list< unsigned char> &t) {
    _size = t.size();
    _five = new unsigned char[_size]{};
    size_t i;
    for(auto sym : t){
        _five[i++] = sym;
    }
    const std::string t_s = std::string(reinterpret_cast<const char*>(_five));
    validation(t_s);
}

Five::Five(const std::string &t) {
    _size = t.size();
    _five = new unsigned char[_size]{};
    size_t i;
    validation(t);
    for(auto sym : t){
        _five[i++] = sym;
    }
}

Five::Five(const Five &other) {
    _size = other._size;
    _five = new unsigned char[_size]{};
    for(size_t i = 0; i < _size; i++)
        _five[i] = other._five[i];
}

Five::Five(Five &&other) noexcept {
    _size = other._size;
    _five = new unsigned char[_size]{};
    for(size_t i = 0; i < _size; i++)
        _five[i] = other._five[i];
    other._size = 0;
    delete other._five;
}

Five::~Five() noexcept {
    _size = 0;
    delete _five;
}


size_t Five::get_size() {
    return _size;
}


unsigned char* Five::get_value() {
    return _five;
}


bool Five::operator>(const Five &other) {
    if(_size > other._size) return true;
    if(other._size > _size) return false;
    
    for(size_t i = _size - 1; i < _size; i--) {
            if(_five[i] > other._five[i])
                return true;
            if(other._five[i] > _five[i])
                return false;
        }
    return false;
}

bool Five::operator<(const Five &other) {
    if(_size < other._size) return true;
    if(other._size < _size) return false;
    
    for(size_t i = _size - 1; i < _size ; i--) {
            if(_five[i] < other._five[i])
                return true;
            if(other._five[i] < _five[i])
                return false;
        }
    return false;
}

bool Five::operator==(const Five &other) {
    if(_size != other._size) return false;
    
    for(size_t i = _size - 1; i < _size ; i--) {
        if(_five[i] != other._five[i])
            return false;
    }
    return true;
}

bool Five::operator!=(const Five &other) {
    if(_size != other._size) return true;
    
    for(size_t i = _size - 1; i < _size ; i--) {
        if(_five[i] != other._five[i])
            return true;
    }
    return false;
}

bool Five::operator>=(const Five &other) {
    if(_size > other._size) return true;
    if(other._size > _size) return false;
    
    for(size_t i = _size - 1; i < _size; i--) {
            if(_five[i] > other._five[i])
                return true;
            if(other._five[i] > _five[i])
                return false;
        }
    return true;
}

bool Five::operator<=(const Five &other) {
    if(_size < other._size) return true;
    if(other._size < _size) return false;
    
    for(size_t i = _size - 1; i < _size ; i--) {
            if(_five[i] < other._five[i])
                return true;
            if(other._five[i] < _five[i])
                return false;
        }
    return true;
}

Five Five::operator+(const Five &other) {
    bool is_longer = _size > other._size;
    size_t bigger_size, smaller_size;
    
    if(is_longer) {
        bigger_size = _size;
        smaller_size = other._size;
    } else {
        bigger_size = other._size;
        smaller_size = _size;
    }
    
    Five result_add = Five(bigger_size);
    
    int addiction, num1, num2, remain = 0;
    for(size_t i = 0; i < smaller_size; i++) {
        num1 = _five[i] - 48;
        num2 = other._five[i] - 48;
        
        addiction = num2 + num1 + remain;
        remain = addiction / 5;
        
        result_add._five[i] = (addiction % 5) + 48;
        
    }
    for(size_t i = smaller_size; i < bigger_size; i++) {
        if(is_longer)
            num1 = _five[i] - 48;
        else
            num1 = other._five[i] - 48;
        
        addiction = num1 + remain;
        remain = addiction / 5;
        
        result_add._five[i] = (addiction % 5) + 48;
    }
        
    if (remain != 0) {
       signed char shift = 1;
       result_add.resize(shift);
       result_add._five[bigger_size] = remain + 48;
    }    
    return result_add;  
    
}

Five Five::operator-(const Five &other) {
     if (other._size > _size)
        throw std::invalid_argument("У нас тут нет кода для отрицательных чисел\n");
 //   if(other._size < _size)
 //       flag = true;
    
    Five result_diff = Five(_size);
    int difference;
    bool reduct = false;
    
    for(size_t i = 0; i < other._size; i++) {
        int minued = _five[i] - 48;
        int subtrahend = other._five[i] - 48;
        
        if ( (subtrahend + reduct) <= minued) {
            difference = minued - (reduct + subtrahend);
            reduct = false;
            
        } 
        if (reduct and minued == 0) {
            difference = 4 - subtrahend;
                  
        }
        if ( subtrahend > minued and !reduct) {
            difference = (5 + minued) - subtrahend;
            reduct = true;
        
        } 

        result_diff._five[i] = difference + 48;    
    }
    
    for(size_t i = other._size; i < _size; i++) {
        int minued = _five[i] - 48;
        if(reduct and minued == 0) {
            difference = 4;

        }
        if(minued != 0) {
            difference = minued - reduct;
            reduct = false;
        }

        result_diff._five[i] = difference + 48;
    }   
    

    signed char shift = 0;
    size_t i = _size - 1;
    while(result_diff._five[i] == '0') {
        shift--;
        i--;
    }
        
   // std::cout << (int)shift << std::endl;
    result_diff.resize(shift);
    
    return result_diff;
}

Five Five::operator=(const Five &other) {
    _size = other._size;
    _five = new unsigned char[_size]{};
    for(size_t i = 0; i < _size; i++)
        _five[i] = other._five[i];
    return *this;
}

bool Five::validation(const std::string &t) {
    for(int i = 0; i < t.length(); i++){
        if (t[i] != 0 and !(t[i] >= 48 and t[i] <= 52))
            throw std::invalid_argument("https://en.wikipedia.org/wiki/Quinary");
    }
    return true;
}

void Five::resize(signed char shift) {
 //   if (shift > _size)
   //     throw std::invalid_argument("Как ты вообще смог получить отричательный размер при разности?");
    
    _size += shift;
    unsigned char* _resized_five = new unsigned char[_size]{};
    
    for(size_t i = 0; i < _size; ++i)
        _resized_five[i] = _five[i];
 //   delete _five;
    _five = _resized_five;
}
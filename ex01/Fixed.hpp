#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int value;
    static const int fractionalBits = 8;
public:
    Fixed();
    Fixed(const int integer);
    Fixed(const float number);
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();
    int getRawBits() const;
    void setRawBits(int const raw);
    float toFloat() const;
    int toInt() const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
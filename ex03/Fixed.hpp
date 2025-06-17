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

    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);
    
    static Fixed& min(Fixed& f1, Fixed& f2);
    static const Fixed& min(const Fixed& f1, const Fixed& f2);
    static Fixed& max(Fixed& f1, Fixed& f2);
    static const Fixed& max(const Fixed& f1, const Fixed& f2);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
    : value(0)
{}

Fixed::Fixed(int integer)
{
    value = integer << fractionalBits;
}

Fixed::Fixed(float number)
{
    value = static_cast<int>(roundf(number * (1 << fractionalBits)));
}

Fixed::Fixed(const Fixed& other)
    : value(other.value)
{}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        this->value = other.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{}

int Fixed::getRawBits() const
{
    return (this->value);
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

float Fixed::toFloat() const
{
    return (static_cast<float>(value) / (1 << fractionalBits));
}

int Fixed::toInt() const
{
    return (value >> fractionalBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return (out);
}

bool Fixed::operator>(const Fixed& other) const
{
    return (value > other.value);
}

bool  Fixed::operator<(const Fixed& other) const
{
    return (value < other.value);
}

bool Fixed::operator>=(const Fixed& other) const
{
    return (value >= other.value);
}

bool Fixed::operator<=(const Fixed& other) const
{
    return (value <= other.value);
}

bool Fixed::operator==(const Fixed& other) const
{
    return (value == other.value);
}

bool Fixed::operator!=(const Fixed& other) const
{
    return (value != other.value);
}

Fixed Fixed::operator+(const Fixed& other) const
{
    return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed& other) const
{
    return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed& Fixed::operator++()
{
    value += 1;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    value += 1;
    return (temp);
}

Fixed& Fixed::operator--()
{
    value -= 1;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    value -= 1;
    return (temp);
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2)
{
    return ((f1 < f2) ? f1 : f2);
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2)
{
    return ((f1 > f2) ? f2 : f1);
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2)
{
    return ((f1 > f2) ? f1 : f2);
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2)
{
    return ((f1 < f2) ? f2 : f1);
}
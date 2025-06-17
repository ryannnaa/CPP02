#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
    : value(0)
{
    std::cout <<"Default constructor called" << std::endl;
}

Fixed::Fixed(int integer)
{
    std::cout <<"Int constructor called" << std::endl;

    value = integer << fractionalBits;
}

Fixed::Fixed(float number)
{
    std::cout <<"Float constructor called" << std::endl;

    value = static_cast<int>(roundf(number * (1 << fractionalBits)));
}

Fixed::Fixed(const Fixed& other)
    : value(other.value)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;

    if (this != &other)
        this->value = other.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    
    return (this->value);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;

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
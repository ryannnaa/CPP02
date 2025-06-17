#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
    : value(0)
{
    std::cout <<"Default constructor called" << std::endl;
}

Fixed::Fixed(int integer)
{
    value = integer << fractionalBits;
}

Fixed::Fixed(float number)
{
    value = static_cast<int>(number * (1 << fractionalBits) + (number >= 0 ? 0.5f : -0.5f));
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
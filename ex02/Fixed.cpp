/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 00:58:42 by lude-bri          #+#    #+#             */
/*   Updated: 2025/05/07 01:28:47 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Default constructor
Fixed::Fixed() : _fixedPoint(0) {}

//copy constructor
Fixed::Fixed(const Fixed &obj) {
	_fixedPoint = obj.getRawBits();
}

//To Int constructor
Fixed::Fixed(const int number) {
	_fixedPoint = number << _bits; 
}

//To Float constructor
Fixed::Fixed(const float number) {
	_fixedPoint = roundf(number * (1 << _bits)); //arredondar para o inteiro mais prox
}

//Default destructor 
Fixed::~Fixed() {
}

Fixed &Fixed::operator=(const Fixed &obj) {
	if (this != &obj) //vou verificar autoatribuicao a = a
		_fixedPoint = obj.getRawBits();
	return (*this);
}

//returns the raw value of the fixed-point value
int	Fixed::getRawBits() const {
	return (_fixedPoint);
}

//toFloat - converts fixed-point value to floating-point value
float	Fixed::toFloat() const {
	return (static_cast<float>(_fixedPoint) / (1 << _bits));
}

//toInt - converts fixed-point value to an integer value
int		Fixed::toInt() const {
	return _fixedPoint >> _bits;
}

//function that sets the raw value of the fixed-point number
void	Fixed::setRawBits(int const raw) {
	_fixedPoint = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}


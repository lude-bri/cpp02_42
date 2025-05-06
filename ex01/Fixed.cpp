/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:05:48 by lude-bri          #+#    #+#             */
/*   Updated: 2025/05/06 14:51:53 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Default constructor
Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
}

//Default constructor
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

//To Int constructor
Fixed::Fixed(const int number) {
	std::cout << "Int constructor called" << std::endl;
	_fixedPoint = number << _bits; 
}

//To Float constructor
Fixed::Fixed(const float number) {
	std::cout << "Float constructor called" << std::endl;
	_fixedPoint = roundf(number * (1 << _bits)); //arredondar para o inteiro mais prox
}
//returns the raw value of the fixed-point value
int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPoint);
}

//toFloat - converts fixed-point value to floating-point value
float	Fixed::toFloat() const {
	return (float)_fixedPoint / (1 << _bits);
}

//toInt - converts fixed-point value to an integer value
int		Fixed::toInt() const {

}

//function that sets the raw value of the fixed-point number
void	Fixed::setRawBits(int const raw) {
	_fixedPoint = raw;
}



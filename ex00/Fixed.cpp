/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 23:57:30 by lude-bri          #+#    #+#             */
/*   Updated: 2025/05/06 14:35:10 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//default constructor
Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	setRawBits(0);
}

//copy constructor
Fixed::Fixed(const Fixed &obj) {
	std::cout << "Copy constructor called" << std::endl;
	_fixedPoint = obj.getRawBits();
}

//copy assignment operator overload
Fixed &Fixed::operator=(const Fixed &obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj) //vou verificar autoatribuicao a = a
		_fixedPoint = obj.getRawBits();
	return (*this);
}

//returns the raw value of the fixed-point value
int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPoint);
}

//function that sets the raw value of the fixed-point number
void	Fixed::setRawBits(int const raw) {
	_fixedPoint = raw;
}

//destructor
Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

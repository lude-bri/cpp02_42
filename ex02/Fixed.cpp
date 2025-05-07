/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 00:58:42 by lude-bri          #+#    #+#             */
/*   Updated: 2025/05/07 02:17:14 by lude-bri         ###   ########.fr       */
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

bool	Fixed::operator>(const Fixed &obj) const {
	return _fixedPoint > obj._fixedPoint;
}

bool	Fixed::operator<(const Fixed &obj) const {
	return _fixedPoint < obj._fixedPoint;
}

bool	Fixed::operator>=(const Fixed &obj) const {
	return _fixedPoint >= obj._fixedPoint;
}

bool	Fixed::operator<=(const Fixed &obj) const {
	return _fixedPoint <= obj._fixedPoint;
}

bool	Fixed::operator==(const Fixed &obj) const {
	return _fixedPoint == obj._fixedPoint;
}

bool	Fixed::operator!=(const Fixed &obj) const {
	return _fixedPoint != obj._fixedPoint;
}

Fixed	Fixed::operator+(const Fixed &obj) const {
	return Fixed(this->toFloat() + obj.toFloat());
}

Fixed	Fixed::operator-(const Fixed &obj) const {
	return Fixed(this->toFloat() - obj.toFloat());
}

Fixed	Fixed::operator*(const Fixed &obj) const {
	return Fixed(this->toFloat() * obj.toFloat());
}

Fixed	Fixed::operator/(const Fixed &obj) const {
	return Fixed(this->toFloat() / obj.toFloat());
}

Fixed	&Fixed::operator++() {
	_fixedPoint++;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed temp(*this); //faco uma copia do estado atual
	_fixedPoint++; //incremento o valor
	return temp; //retorno a copia antiga (sem incremento)
}

Fixed	&Fixed::operator--() {
	_fixedPoint--;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed temp(*this);
	_fixedPoint--;
	return temp;
}

Fixed	&Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b) ? a : b;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b) ? a : b;
}

//toFloat - converts fixed-point value to floating-point value
float	Fixed::toFloat() const {
	return (static_cast<float>(_fixedPoint) / (1 << _bits));
}

//toInt - converts fixed-point value to an integer value
int		Fixed::toInt() const {
	return _fixedPoint >> _bits;
}

//returns the raw value of the fixed-point value
int	Fixed::getRawBits() const {
	return (_fixedPoint);
}

//function that sets the raw value of the fixed-point number
void	Fixed::setRawBits(int const raw) {
	_fixedPoint = raw;
}

//operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 00:57:58 by lude-bri          #+#    #+#             */
/*   Updated: 2025/05/07 01:45:34 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

//LIBRARIES
#include <iostream>
#include <math.h>

//COLORS
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define RESET   "\033[0m"
# define BOLD    "\033[1m"
# define BLINK    "\033[5m" 
# define REVERSE  "\033[7m"

//CLASSES
class Fixed {

	private:
		int					_fixedPoint;
		static const int	_bits = 8;

	public:
		Fixed();
		Fixed(const Fixed &obj);
		Fixed(const int	number);
		Fixed(const float number);
		~Fixed();
	
		//operadores de comparacao
		Fixed &operator=(const Fixed &obj);
		bool  operator>(const Fixed &obj) const;
		bool  operator<(const Fixed &obj) const;
		bool  operator>=(const Fixed &obj) const;
		bool  operator<=(const Fixed &obj) const;
		bool  operator==(const Fixed &obj) const;
		bool  operator!=(const Fixed &obj) const;

		//operadores aritmeticos
		Fixed	operator+(const Fixed &obj) const;
		Fixed	operator-(const Fixed &obj) const;
		Fixed	operator*(const Fixed &obj) const;
		Fixed	operator/(const Fixed &obj) const;

		//operador de incremento/decremento
		Fixed &operator++(); //pre-increment (++a)
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);

		//static memfunct
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
		
		int			getRawBits() const;
		void		setRawBits(int const raw);
		float		toFloat() const;
		int			toInt() const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif

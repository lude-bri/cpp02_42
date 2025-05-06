/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:05:45 by lude-bri          #+#    #+#             */
/*   Updated: 2025/05/06 14:47:47 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <math.h>

class Fixed {

	private:
		int					_fixedPoint;
		static const int	_bits = 8;

	public:
		Fixed();
		Fixed(const int	number);
		Fixed(const float number);
		Fixed &operator=(const Fixed &obj);
		~Fixed();

		int			getRawBits() const;
		void		setRawBits(int const raw);
		float		toFloat() const;
		int			toInt() const;
};

#endif

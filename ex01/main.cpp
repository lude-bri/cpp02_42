/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:05:39 by lude-bri          #+#    #+#             */
/*   Updated: 2025/05/06 13:23:12 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main()
{
	Fixed	a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is" << a << std::endl;
	std::cout << "b is" << b << std::endl;
	std::cout << "c is" << c << std::endl;
	std::cout << "d is" << d << std::endl;

	std::cout << "a is" << a.toInt() << std::endl;
	std::cout << "b is" << b.toInt() << std::endl;
	std::cout << "c is" << c.toInt() << std::endl;
	std::cout << "d is" << d.toInt() << std::endl;

	return 0;
}

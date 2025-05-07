/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 00:59:02 by lude-bri          #+#    #+#             */
/*   Updated: 2025/05/07 01:03:50 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Fixed.hpp"
//
// int	main(void)
// {
// 	Fixed		a;
// 	Fixed const b(Fixed(5.05f) * Fixed(2));
//
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
//
// 	std::cout << b << std::endl;
//
// 	std::cout << Fixed::max(a, b) << std::endl;
//
// 	return 0;
// }

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

void runTests() {
    std::cout << "========== EX02 TESTS - CPP02 ==========\n" << std::endl;

    // Test 1: Fixed object creation
    std::cout << "\n--- Test 1: Object creation ---" << std::endl;
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;

    // Test 2: Comparison operators
    std::cout << "\n--- Test 2: Comparison operators ---" << std::endl;
    std::cout << "a < b: " << (a < b) << " (expected: 1)" << std::endl;
    std::cout << "b > a: " << (b > a) << " (expected: 1)" << std::endl;
    std::cout << "c <= d: " << (c <= d) << " (expected: 0)" << std::endl;
    std::cout << "d >= b: " << (d >= b) << " (expected: 1)" << std::endl;
    std::cout << "a == b: " << (a == b) << " (expected: 0)" << std::endl;
    std::cout << "b == d: " << (b == d) << " (expected: 1)" << std::endl;
    std::cout << "a != b: " << (a != b) << " (expected: 1)" << std::endl;
    std::cout << "b != d: " << (b != d) << " (expected: 0)" << std::endl;

    // Test 3: Arithmetic operators
    std::cout << "\n--- Test 3: Arithmetic operators ---" << std::endl;
    Fixed e = a + b;
    Fixed f = c - b;
    Fixed g = b * c;
    Fixed h = c / b;

    std::cout << "a + b: " << e << " (expected: 10)" << std::endl;
    std::cout << "c - b: " << f << " (expected: ~32.42)" << std::endl;
    std::cout << "b * c: " << g << " (expected: ~424.2)" << std::endl;
    std::cout << "c / b: " << h << " (expected: ~4.242)" << std::endl;

    // Test 4: Increment/decrement operators
    std::cout << "\n--- Test 4: Increment/decrement operators ---" << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "--a: " << --a << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "a--: " << a-- << std::endl;
    std::cout << "a: " << a << std::endl;

    // Test 5: min/max functions
    std::cout << "\n--- Test 5: min/max functions ---" << std::endl;
    std::cout << "min(a, b): " << Fixed::min(a, b) << " (expected: 0)" << std::endl;
    std::cout << "max(a, b): " << Fixed::max(a, b) << " (expected: 10)" << std::endl;
    std::cout << "min(c, d): " << Fixed::min(c, d) << " (expected: 10)" << std::endl;
    std::cout << "max(c, d): " << Fixed::max(c, d) << " (expected: ~42.42)" << std::endl;

    // Test 6: Edge cases
    std::cout << "\n--- Test 6: Edge cases ---" << std::endl;
    Fixed const big(8388607.0f / (1 << 8));  // Maximum representable value
    Fixed const small(-8388608.0f / (1 << 8)); // Minimum representable value

    std::cout << "big: " << big << std::endl;
    std::cout << "small: " << small << std::endl;
    std::cout << "big + small: " << big + small << std::endl;
    std::cout << "big - small: " << big - small << std::endl;

    std::cout << "\n========== TESTS COMPLETE ==========\n" << std::endl;
}

int main(void) {
    runTests();
    return 0;
}

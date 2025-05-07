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

#include "Fixed.hpp"

int	main(void)
{
	Fixed		a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;

	return 0;
}

// #include <cmath>
//
// void printTestHeader(const std::string& title) {
//     std::cout << BOLD << BLUE << "\n=== " << title << " ===" << RESET << std::endl;
// }
//
// void printTestResult(const std::string& description, bool passed) {
//     std::cout << " • " << description << ": " 
//               << (passed ? (GREEN "✓ PASS" RESET) : (RED "✗ FAIL" RESET)) 
//               << std::endl;
// }
//
// void runTests() {
//     std::cout << BOLD << MAGENTA << "\n========== " << REVERSE << " EX02 TESTS - CPP02 " << RESET 
//               << BOLD << MAGENTA << " ==========\n" << RESET << std::endl;
//
//     // Test 1: Fixed object creation
//     printTestHeader("OBJECT CREATION");
//     Fixed a;
//     Fixed const b(10);
//     Fixed const c(42.42f);
//     Fixed const d(b);
//
//     std::cout << CYAN << "a: " << RESET << a << std::endl;
//     std::cout << CYAN << "b: " << RESET << b << std::endl;
//     std::cout << CYAN << "c: " << RESET << c << std::endl;
//     std::cout << CYAN << "d: " << RESET << d << std::endl;
//
//     // Test 2: Comparison operators
//     printTestHeader("COMPARISON OPERATORS");
//     printTestResult("a < b", (a < b) == true);
//     printTestResult("b > a", (b > a) == true);
//     printTestResult("c <= d", (c <= d) == false);
//     printTestResult("d >= b", (d >= b) == true);
//     printTestResult("a == b", (a == b) == false);
//     printTestResult("b == d", (b == d) == true);
//     printTestResult("a != b", (a != b) == true);
//     printTestResult("b != d", (b != d) == false);
//
//     // Test 3: Arithmetic operators
//     printTestHeader("ARITHMETIC OPERATORS");
//     Fixed e = a + b;
//     Fixed f = c - b;
//     Fixed g = b * c;
//     Fixed h = c / b;
//
//     std::cout << YELLOW << "a + b: " << RESET << e << " (expected: " << GREEN "10" RESET ")" << std::endl;
//     std::cout << YELLOW << "c - b: " << RESET << f << " (expected: " << GREEN "~32.42" RESET ")" << std::endl;
//     std::cout << YELLOW << "b * c: " << RESET << g << " (expected: " << GREEN "~424.2" RESET ")" << std::endl;
//     std::cout << YELLOW << "c / b: " << RESET << h << " (expected: " << GREEN "~4.242" RESET ")" << std::endl;
//
//     // Test 4: Increment/decrement operators
//     printTestHeader("INCREMENT/DECREMENT OPERATORS");
//     std::cout << CYAN << "Initial a: " << RESET << a << std::endl;
//     std::cout << "++a: " << BLUE << ++a << RESET << std::endl;
//     std::cout << "a after prefix ++: " << a << std::endl;
//     std::cout << "a++: " << BLUE << a++ << RESET << std::endl;
//     std::cout << "a after postfix ++: " << a << std::endl;
//     std::cout << "--a: " << MAGENTA << --a << RESET << std::endl;
//     std::cout << "a after prefix --: " << a << std::endl;
//     std::cout << "a--: " << MAGENTA << a-- << RESET << std::endl;
//     std::cout << "a after postfix --: " << a << std::endl;
//
//     // Test 5: min/max functions
//     printTestHeader("MIN/MAX FUNCTIONS");
//     std::cout << "min(a, b): " << GREEN << Fixed::min(a, b) << RESET << " (expected: " << GREEN "0" RESET ")" << std::endl;
//     std::cout << "max(a, b): " << GREEN << Fixed::max(a, b) << RESET << " (expected: " << GREEN "10" RESET ")" << std::endl;
//     std::cout << "min(c, d): " << GREEN << Fixed::min(c, d) << RESET << " (expected: " << GREEN "10" RESET ")" << std::endl;
//     std::cout << "max(c, d): " << GREEN << Fixed::max(c, d) << RESET << " (expected: " << GREEN "~42.42" RESET ")" << std::endl;
//
//     // Test 6: Edge cases
//     printTestHeader("EDGE CASES");
//     Fixed const big(8388607.0f / (1 << 8));  // Maximum representable value
//     Fixed const small(-8388608.0f / (1 << 8)); // Minimum representable value
//
//     std::cout << RED << "big: " << RESET << big << std::endl;
//     std::cout << RED << "small: " << RESET << small << std::endl;
//     std::cout << "big + small: " << (big + small) << std::endl;
//     std::cout << "big - small: " << (big - small) << std::endl;
//
//     std::cout << BOLD << BLINK << GREEN << "\n========== ALL TESTS COMPLETED ==========\n" << RESET << std::endl;
// }
//
// int main(void) {
//     runTests();
//     return 0;
// }

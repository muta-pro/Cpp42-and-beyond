/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:39:37 by imutavdz          #+#    #+#             */
/*   Updated: 2026/03/28 14:27:23 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int	main(void)
{
	Fixed		a;
	Fixed const	b(10);
	Fixed const	c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	// std::cout << "===== EXTRA TESTS =====" << std::endl;
	
	// // Test integer constructor
	// Fixed y(5);
	// std::cout << "y (created from int 5): " << y << std::endl;
	// std::cout << "y.toInt(): " << y.toInt() << std::endl;
	// std::cout << "y.toFloat(): " << y.toFloat() << std::endl;
	// std::cout << std::endl;

	// // Test float constructor
	// Fixed z(3.75f);
	// std::cout << "z (created from float 3.75): " << z << std::endl;
	// std::cout << "z.toInt(): " << z.toInt() << std::endl;
	// std::cout << "z.toFloat(): " << z.toFloat() << std::endl;
	// std::cout << std::endl;

	// // Test negative numbers
	// Fixed q(-2.5f);
	// std::cout << "q (created from float -2.5): " << q << std::endl;
	// std::cout << "q.toInt(): " << q.toInt() << std::endl;
	// std::cout << std::endl;

	// // Test zero
	// Fixed w(0);
	// std::cout << "w (created from int 0): " << w << std::endl;
	// std::cout << std::endl;

	// // Test small decimal
	// Fixed e(0.5f);
	// std::cout << "e (created from float 0.5): " << e << std::endl;
	// std::cout << std::endl;

	// std::cout << "===== OVERFLOW TESTS =====" << std::endl;
	
	// // Test with a SAFE large number
	// Fixed f(1000);
	// std::cout << "f (created from int 1000): " << f << std::endl;
	// std::cout << std::endl;

	// // Test with an UNSAFE large number (will trigger warning)
	// std::cout << "Attempting to create Fixed from int 10000000 (may overflow):" << std::endl;
	// Fixed g(10000000);
	// std::cout << "g: " << g << std::endl;
	// std::cout << std::endl;

	// // Test with float that will overflow
	// std::cout << "Attempting to create Fixed from float 1e8 (will overflow):" << std::endl;
	// Fixed h(1e8f);
	// std::cout << "h: " << h << std::endl;
	// std::cout << std::endl;

	// std::cout << "===== COPY & ASSIGNMENT =====" << std::endl;
	
	// // Test copy constructor
	// Fixed i(a);
	// std::cout << "i (copy of a): " << i << std::endl;
	// std::cout << std::endl;

	// // Test assignment operator
	// Fixed j(0);
	// j = b;
	// std::cout << "j (assigned from b): " << j << std::endl;
	// std::cout << std::endl;

	return (0);
}

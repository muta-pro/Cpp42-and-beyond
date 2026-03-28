/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 12:17:15 by imutavdz          #+#    #+#             */
/*   Updated: 2026/03/28 14:29:57 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

int main() {
	
	Point	a (0.0f, 0.0f);
	Point	b (10.0f, 0.0f);
	Point	c (0.0f, 10.0f);

	Point	p1 (2.0f, 2.0f);
	Point	p2 (9.0f, 9.0f);
	Point	p3 (0.0f, 0.0f);
	Point	p4 (5.0f, 0.0f);

	if (bsp(a, b, c, p1) == true) {
		std::cout << "P1 is inside" << std::endl;
	}
	else
		std::cout << "P1 is outside" << std::endl;
	if (bsp(a, b, c, p2) == true) {
		std::cout << "P2 is inside" << std::endl;
	}
	else
		std::cout << "P2 is outside" << std::endl;
	if (bsp(a, b, c, p3) == true) {
		std::cout << "P3 is inside" << std::endl;
	}
	else
		std::cout << "P3 is outside" << std::endl;
	if (bsp(a, b, c, p4) == true) {
		std::cout << "P4 is inside" << std::endl;
	}
	else
		std::cout << "P4 is outside" << std::endl;
	return (0);
}
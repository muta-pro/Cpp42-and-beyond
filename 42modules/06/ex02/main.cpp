/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 08:53:27 by imutavdz          #+#    #+#             */
/*   Updated: 2026/06/28 11:00:26 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
	int rndm = std::rand() % 3;

	if (rndm == 0) {
		std::cout << "generated: A";
		return new A();
	}
	else if (rndm == 1) {
		std::cout << "generated: B";
		return new B();
	}
	else {
		std::cout << "generated: C";
		return new C();
	}

}

void identify(Base *p) {
	if (dynamic_cast<A*>(p) != nullptr)
		std::cout << "\npointer identifed as A";
	else if (dynamic_cast<B*>(p) != nullptr)
		std::cout << "\npointer identifed as B";
	else if (dynamic_cast<C*>(p) != nullptr)
		std::cout << "\npointer identifed as C";
	else
		std::cout << "\npointer unknown" << std::endl;
}

void identify(Base &p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "\nreference A";
		return;
	}
	catch (const std::exception &e) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "\nreference B";
		return;
	}
	catch (const std::exception &e) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "\nreference C";
		return;
	}
	catch (const std::exception &e) {}
	std::cout << "\nreference unknown" << std::endl;
}

int main()
{	//casting to unsigned int bc time returns 64bits and srand() expects 32bits
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	for (int i = 0; i < 5; i++) {
		std::cout << "\ntest " << i + 1 << ":" << std::endl;

		Base *rndmObj = generate();
		identify(rndmObj);
		identify(*rndmObj);
		delete rndmObj;
	}
	return 0;
}
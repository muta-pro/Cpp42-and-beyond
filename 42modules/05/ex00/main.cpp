/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 08:59:11 by imutavdz          #+#    #+#             */
/*   Updated: 2026/05/29 13:32:40 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat OK ("OK", 34);
		std::cout << OK << std::endl;
	}
	//base class match works bc of polymotphism
	catch (std::exception &e) {
		std::cerr << "Except: " << e.what() << std::endl;
	}
	try {
		Bureaucrat BAD ("BAD", 0);
		std::cout << "this line is skipped, not printed" << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Except. catch: " << e.what() << std::endl;
	}
	try {
		Bureaucrat WORSE ("WORSE", 155);
		std::cout << WORSE << std::endl;//skipped
	}
	catch (std::exception &e) {
		std::cerr << "Except. catch: " << e.what() << std::endl;
	}
	try {
		Bureaucrat inc ("high", 2);
		std::cout << inc << std::endl;
		inc.incGrade();
		std::cout << "First increment: " << inc << std::endl;
		inc.incGrade();
		std::cout << "Second increment: " << inc << std::endl;
	}
	catch (std::exception &e) {
		std::cerr  << "Except. catch: " << e.what() << std::endl;
	}
	try {
		Bureaucrat dec ("low", 146);
		std::cout << dec << std::endl;
		dec.decGrade();
		std::cout << "First decrement: " << dec << std::endl;
		dec.decGrade();
		dec.decGrade();
		dec.decGrade();
		dec.decGrade();
		std::cout << "Many decr: never printed line" << dec << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Except. catch: " << e.what() << std::endl;

	}
	return 0;
}
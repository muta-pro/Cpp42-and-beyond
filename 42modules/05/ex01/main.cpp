/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 08:59:11 by imutavdz          #+#    #+#             */
/*   Updated: 2026/05/18 14:15:52 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {
		Bureaucrat A ("A", 5);
		Bureaucrat B ("B", 50);
		Bureaucrat C ("C", 100);
		std::cout << A;
		std::cout << B;
		std::cout << C;
		std::cout << std::endl;

		Form High ("TOP SECRET", 10, 5);
		Form Low ("RANDOM", 100, 50);

		std::cout << High;
		std::cout << Low;
		std::cout << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Except: " << e.what() << std::endl;
	}
	try {
		Bureaucrat BAD ("BAD", 0);
		std::cout << BAD << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Except. catch: " << e.what() << std::endl;
	}
	try {
		Bureaucrat WORSE ("WORSE", 155);
		std::cout << WORSE << std::endl;
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
		std::cout << "Many decr: " << dec << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Except. catch: " << e.what() << std::endl;

	}
	return 0;
}
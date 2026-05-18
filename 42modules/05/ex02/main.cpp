/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 08:59:11 by imutavdz          #+#    #+#             */
/*   Updated: 2026/05/19 00:07:15 by imutavdz         ###   ########.fr       */
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
	std::cout << "\nSigning Forms\n" << std::endl;
	try {
		Bureaucrat A ("A", 5);
		Bureaucrat B ("B", 50);

		Form report ("report", 40, 20);
		std::cout << "To sign 40 is required, to exec 20" << std::endl;
		std::cout << "A is grade 5" << std::endl;
		A.signForm(report);
		std::cout << "Success!" << std::endl;
		std ::cout << "B is grade 50" << std::endl;
		B.signForm(report);
		std::cout << "Fail!" << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Except. catch: " << e.what() << std::endl;
	}
	std::cout << "\nGrade variation:\n" << std::endl;
	try {
		Bureaucrat C ("C", 50);
		std::cout << "Start: " << C << std::endl;
		std::cout << "C gets decrement: " << std::endl;
		C.decGrade();
		C.decGrade();
		std::cout << C; 
		Bureaucrat D ("D", 150);
		std::cout << "Start: " << D << std::endl;
		std::cout << "D gets increment: " << std::endl;
		D.incGrade();
		std::cout << D;

	}
	catch (std::exception &e) {
		std::cerr << "Except. catch: " << e.what() << std::endl;
	}
	std::cout << "Exception handling: Bureaucrat with grade 0 \n" << std::endl;
	try {
		Bureaucrat zero ("high", 0);
	}
	catch (Bureaucrat::TooHighExc &e) {
		std::cerr  << "Except. catch: " << e.what() << std::endl;
	}
	try {
		Bureaucrat invalid ("invalid", 200);
	}
	catch (Bureaucrat::TooLowExc &e) {
		std::cerr << "Except. catch: " << e.what() << std::endl;
	}
	try {
		Bureaucrat CEO ("CEO",  1);
		std::cout << CEO;
		std::cout << "CEO try gets increment" << std::endl;
		CEO.incGrade();
	}
	catch (Bureaucrat::TooHighExc &e) {
		std::cout << "Except. catch: " << e.what() << std::endl;
	}
	return 0;
}
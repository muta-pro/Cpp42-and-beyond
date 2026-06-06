/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 08:59:11 by imutavdz          #+#    #+#             */
/*   Updated: 2026/06/06 17:30:52 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(NULL));

	Bureaucrat A("A", 5);
	Bureaucrat B("B", 75);
	std::cout << A << B;

	ShubberyCreationForm shrubbery("park");
	std::cout << shrubbery << std::endl;

	A.signForm(shrubbery);
	A.execForm(shrubbery);

	RobotomyRequestForm robot("Marvin");
	std::cout << robot << std::endl;

	A.signForm(robot);
	A.execForm(robot);

	PresidentialPardonForm pardon("Prisoner");
	std::cout << pardon << std::endl;

	A.signForm(pardon);
	A.execForm(pardon);

	RobotomyRequestForm robot2("Target");
	B.signForm(robot2);

	ShubberyCreationForm tree("home");
	A.execForm(tree);

	ShubberyCreationForm tree2("garden");
	B.signForm(tree2);
	B.execForm(tree2);

	std::cout << "\n Bureaucrat construction and inc/dec grades\n" << std::endl;

	try {
		Bureaucrat top("top", 0);
		top.incGrade();
	}
	catch (std::exception &e) {
		std::cout << "Caught: " << e.what() << std::endl;
	}
	try {
		Bureaucrat bottom("bottom", 150);
		bottom.decGrade();
	}
	catch (std::exception &e) {
		std::cout << "Caught: " << e.what() << std::endl;
	}
	try {
		Bureaucrat tooHigh("BOB", 0);
	}
	catch (std::exception &e) {
		std::cout << "Caught: " << e.what() << std::endl;
	}
	try {
		Bureaucrat tooLow("BOBY", 151);
	}
	catch (std::exception &e) {
		std::cout << "Caught: " << e.what() << std::endl;
	}
	try {
		ShubberyCreationForm tree("direct_test");
		A.execForm(tree);
	}
	catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}

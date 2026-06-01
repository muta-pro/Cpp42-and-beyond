/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 08:59:11 by imutavdz          #+#    #+#             */
/*   Updated: 2026/06/01 09:55:06 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShubberyCreationForm.hpp"
#include "RoboromyRequestForm.hpp"
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

	return 0;
}
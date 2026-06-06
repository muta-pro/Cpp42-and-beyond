/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 08:59:11 by imutavdz          #+#    #+#             */
/*   Updated: 2026/06/06 15:24:38 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(NULL));
	Intern intern;

	AForm *form01 = intern.makeForm("RobotomyRequestForm", "Bender");
	AForm *form02 = intern.makeForm("PresidentialPardonForm", "Go");

	if (form01) {
		std::cout << *form01 << std::endl;
		delete form01;
	}
	if (form02) {
		std::cout << *form02 << std::endl;
		delete form02;
	}

	AForm *badFrom = intern.makeForm("BAD", "no one");
	(void)badFrom;

	Bureaucrat boss("Boss", 1);
	//receives a pointer from intern and then uses it
	AForm *form03 = intern.makeForm("ShubberyCreationForm", "Turtle");
	if (form03) {
		boss.signForm(*form03);
		boss.execForm(*form03);
		delete form03;
	}
	return 0;
}
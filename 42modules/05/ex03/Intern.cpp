/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 17:03:12 by imutavdz          #+#    #+#             */
/*   Updated: 2026/06/06 15:03:44 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &copy) { (void)copy; }

Intern &Intern::operator=(const Intern &assign) {
	(void)assign;
		return *this;
}

Intern::~Intern() {}

AForm *Intern::createPPF(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm *Intern::createRRF(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm *Intern::createSCF(std::string target) {
	return new ShubberyCreationForm(target);
}
//creators is an array of 3 pointers to Intern member functions.
//Each function takes a std::string and returns an AForm *
//member function pointer needs the class name
AForm *Intern::makeForm(std::string fName, std::string fTarget) const {
	std::string name[3] = {
		"PresidentialPardonForm",
		"RobotomyRequestForm",
		"ShubberyCreationForm"
	};
	//means pointers to functions that take string nad return AForm*
	AForm *(*creators[3])(std::string) = {
		&Intern::createPPF, 
		&Intern::createRRF, 
		&Intern::createSCF
	};

	for (int i = 0; i < 3; i++) {
		if (fName == name[i]) {
			std::cout << "Intern creates " << fName << std::endl;
			return (creators[i])(fTarget);
			//Call the selected creation function on this Intern object.
			//pass target to it
		}
	}
	std::cout << fName << "Form doesn't exist" << std::endl;
	return NULL;
}
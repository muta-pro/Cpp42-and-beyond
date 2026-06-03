/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 13:08:49 by imutavdz          #+#    #+#             */
/*   Updated: 2026/06/01 10:00:55 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
	: AForm(copy), _target(copy._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &assign) {
	AForm::operator=(assign);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::beExec(const Bureaucrat &executor) const {
	(void)executor;
	std::cout << "* DRRRRRR *" << std::endl;
	if (rand() % 2) {
		std::cout << _target << " has been robotomized " << std::endl;
	}
	else {
		std::cout << "Robotomy of " << _target << " failed" << std::endl;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 23:19:55 by imutavdz          #+#    #+#             */
/*   Updated: 2026/06/01 08:53:19 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
	: AForm(copy), _target(copy._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &assign) {
	AForm::operator=(assign);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::beExec(const Bureaucrat &executor) const {
	(void)executor;
	std::cout << _target << " has been pardoned by Zaphod Beeblebox. " << std::endl;
}

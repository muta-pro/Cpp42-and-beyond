/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShubberyCreationForm.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 13:08:49 by imutavdz          #+#    #+#             */
/*   Updated: 2026/05/30 15:12:06 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//creates files

#include "ShubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShubberyCreationForm::ShubberyCreationForm(const std::string &target) 
	: AForm("ShubberyCreationForm", 145, 137), _target(target) {}

ShubberyCreationForm::ShubberyCreationForm(const ShubberyCreationForm &copy)
	: AForm(copy), _target(copy._target) {}

ShubberyCreationForm &ShubberyCreationForm::operator=(const ShubberyCreationForm &assign) {
	AForm::operator=(assign);
	return *this;
}

ShubberyCreationForm::~ShubberyCreationForm() {}

void ShubberyCreationForm::beExec(const Bureaucrat &executor) const {
	std::string filename = _target + "_shrubbery";
	std::ofstream file(filename.c_str());

	if (!file.is_open()) {
		std::cerr << "Error: could not create file " << filename << std::endl;
		return ;
	}

	file << "        _-_\n";
	file << "     /~~   ~~\\\n";
	file << "  /~~         ~~\\\n";
	file << " {               }\n";
	file << "  \\  _-     -_  /\n";
	file << "    ~  \\ //  ~\n";
	file << "        ||\n";
	file << "        ||\n";
	file << "       _||_\n";
	file << "\\n";
	file << "        _-_\n";
	file << "     /~~   ~~\\\n";
	file << "  /~~         ~~\\\n";
	file << " {               }\n";
	file << "  \\  _-     -_  /\n";
	file << "    ~  \\ //  ~\n";
	file << "        ||\n";
	file << "        ||\n";
	file << "       _||_\n";

	file.close();
	std::cout << executor.getName() << " created " << filename << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 12:45:00 by imutavdz          #+#    #+#             */
/*   Updated: 2026/05/19 23:36:49 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>

AForm::AForm() : _name("default"), _isSigned(false), _gradeS(150), _gradeE(150) {}

AForm::AForm(const std::string &name, int gradeS, int gradeE) : _name(name),
	_isSigned(false), _gradeS(gradeS), _gradeE(gradeE) {
		if (gradeS < 1 || _gradeE < 1)
			throw AForm::TooHighExc();
		if (gradeS > 150 || _gradeE > 150)
			throw AForm::TooLowExc();
	}

AForm::AForm(const AForm &copy) : _name(copy._name), _isSigned(copy._isSigned),
	_gradeS(copy._gradeS), _gradeE(copy._gradeE) {}

AForm &AForm::operator=(const AForm &assign) {
	if (this != &assign) {
		_isSigned = assign._isSigned;
	}
	return *this;
}

AForm::~AForm() {}

const std::string &AForm::getName() const {
	return _name;
}

bool AForm::getIsSigned() const {
	return _isSigned;
}

int AForm::getGradeS() const {
	return _gradeS;
}

int AForm::getGradeE() const {
	return _gradeE;
}
//interaction
void AForm::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > _gradeS) {
		throw AForm::TooLowExc();
	}
	_isSigned = true;
	return ;
}

const char* AForm::TooHighExc::what() const throw() {
	return "Form grade is too high";
}

const char* AForm::TooLowExc::what() const throw() {
	return "Form grade is too low";
}

void AForm::execute(const Bureaucrat &b) const
{
	if (_isSigned == false)
		throw (AForm::NotSignedExc());
	if (b.getGrade() > _gradeE)
		throw (AForm::TooLowExc());
	beExec();
	return ;
}

const char *AForm::AlreadySignedExc::what() const throw() {
	return ("Form already signed");
}

const char *AForm::NotSignedExc::what() const throw() {
	return ("Form has not be signed");
}

std::ostream &operator<<(std::ostream &out, const AForm &f) {
	out << "\nForm: " << f.getName()
		<< ", Signed: " << (f.getIsSigned() ? "Yes" : "No")
		<< ", Grade required to sign: " << f.getGradeS()
		<< ", Grade required to exec: " << f.getGradeE();
		return out;
}



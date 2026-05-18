/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 12:45:00 by imutavdz          #+#    #+#             */
/*   Updated: 2026/05/19 00:01:58 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _isSigned(false), _gradeS(150), _gradeE(150) {}

Form::Form(const std::string &name, int gradeS, int gradeE) : _name(name),
	_isSigned(false), _gradeS(gradeS), _gradeE(gradeE) {
		if (gradeS < 1 || _gradeE < 1)
			throw Form::TooHighExc();
		if (gradeS > 150 || _gradeE > 150)
			throw Form::TooLowExc();
	}

Form::Form(const Form &copy) : _name(copy._name), _isSigned(copy._isSigned),
	_gradeS(copy._gradeS), _gradeE(copy._gradeE) {}

Form &Form::operator=(const Form &assign) {
	if (this != &assign) {
		_isSigned = assign._isSigned;
	}
	return *this;
}

Form::~Form() {}

const std::string &Form::getName() const {
	return _name;
}

bool Form::getIsSigned() const {
	return _isSigned;
}

int Form::getGradeS() const {
	return _gradeS;
}

int Form::getGradeE() const {
	return _gradeE;
}
//interaction
void Form::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > _gradeS) {
		throw Form::TooLowExc();
	}
	_isSigned = true;
}

const char* Form::TooHighExc::what() const throw() {
	return "Form grade is too high";
}

const char* Form::TooLowExc::what() const throw() {
	return "Form grade is too low";
}

std::ostream &operator<<(std::ostream &out, const Form &f) {
	out << "\nForm: " << f.getName()
		<< ", Signed: " << (f.getIsSigned() ? "Yes" : "No")
		<< ", Grade required to sign: " << f.getGradeS()
		<< ", Grade required to exec: " << f.getGradeE();
		return out;
}



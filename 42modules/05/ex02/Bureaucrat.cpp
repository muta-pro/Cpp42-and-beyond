/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 08:59:11 by imutavdz          #+#    #+#             */
/*   Updated: 2026/06/01 09:57:08 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}
//name here is const so can only be in init in member list
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name) {
	if (grade < 1)
		throw Bureaucrat::TooHighExc();
	if (grade > 150)
		throw Bureaucrat::TooLowExc();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
	: _name(copy._name), _grade(copy._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &assign) {
	if (this != &assign)
	{
		_grade =  assign._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::decGrade() {
	if (_grade + 1 > 150)
		throw Bureaucrat::TooLowExc();
	_grade++;
}

void Bureaucrat::incGrade() {
	if (_grade - 1 < 1)
		throw Bureaucrat::TooHighExc();
	_grade--;
}

const char* Bureaucrat::TooHighExc::what() const throw() {
	return "Grade too high";
}

const char* Bureaucrat::TooLowExc::what() const throw() {
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.getName() << " bureaucrat grade: \n" << b.getGrade() << std::endl;
	return out;
}

void Bureaucrat::signForm(AForm &f) const {
	try {
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << _name << " cannot sign " << f.getName()
		<< " because " << e.what() << std::endl;
	}
}
//takes ref from baseclass then calls concrete class exec and catches possible exc
void Bureaucrat::execForm(AForm &f) const {
	try {
		f.execute(*this);
		std::cout << _name << " executed " << f.getName() << std::endl;
	}
	catch (AForm::NotSignedExc &e) {
		std::cout << _name << " cannot execute " << f.getName()
		<< " because " << e.what() << std::endl;
	}
	catch (AForm::TooLowExc &e) {
		std::cout << _name << " couldn't execute " << f.getName()
		<< " because " << e.what() << std::endl;
	}
}
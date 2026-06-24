/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 08:59:11 by imutavdz          #+#    #+#             */
/*   Updated: 2026/06/23 00:20:22 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

//name here is const so can only be in init in member list
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name) {
	if (grade < minGrade)
		throw Bureaucrat::TooHighExc();
	if (grade > maxGrade)
		throw Bureaucrat::TooLowExc();
	_grade = grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &assign) {
	if (this != &assign)
	{
		_grade =  assign._grade;
	}
	return *this;
}

const std::string &Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::decGrade() {
	if (_grade + 1 > maxGrade)
		throw Bureaucrat::TooLowExc();
	_grade++;
}

void Bureaucrat::incGrade() {
	if (_grade - 1 < minGrade)
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

void Bureaucrat::signForm(Form &f) {
	try {
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << _name << " cannot sign " << f.getName()
		<< " because " << e.what() << std::endl;
	}
}
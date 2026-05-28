/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 08:49:16 by imutavdz          #+#    #+#             */
/*   Updated: 2026/05/28 19:59:56 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {
	public:
			Bureaucrat();
			//we need this for the main tests
			Bureaucrat(const std::string &name, int grade);
			Bureaucrat(const Bureaucrat &copy);
			Bureaucrat &operator=(const Bureaucrat &assign);
			~Bureaucrat();

			const std::string &getName() const;
			int getGrade() const;

			void incGrade();
			void decGrade();
			//exception classes - nested class
			//public means - access level(base methods remain pubblic)
			class TooHighExc : public std::exception {
			public:
				virtual const char *what() const throw();
			};

			class TooLowExc : public std::exception {
			public:
				virtual const char *what() const throw();
			};

	private:
			const std::string _name; //const means pass during instantiation
			int _grade;//is also passed during instantiation
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat& b);

#endif
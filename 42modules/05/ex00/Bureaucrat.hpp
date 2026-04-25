/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 08:49:16 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/25 09:04:56 by imutavdz         ###   ########.fr       */
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
			Bureaucrat(const Bureaucrat &copy);
			Bureaucrat &operator=(const Bureaucrat &assign);
			~Bureaucrat();

			const std::string &getname() const;
			int getGrade() const;

			void incGrade();
			void decGrade();

			class TooHighExc : public std::exception {
			public:
				virtual const char *what() const throw();
			};

			class TooLowExc : public std::exception {
			public:
				virtual const char *what() const throw();
			};

	private:
			const std::string _name;
			int _grade;
};

std::ostream &operator<<(std::ostream& os, const Bureaucrat& b);

#endif
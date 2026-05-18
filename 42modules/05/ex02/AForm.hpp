/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 12:45:04 by imutavdz          #+#    #+#             */
/*   Updated: 2026/05/18 23:57:17 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class Form {
	public:
		Form();
		Form(const std::string &name, int gradeS, int gradeE);
		Form(const Form &copy);
		Form &operator=(const Form &assign);
		~Form();

		const std::string &getName() const;
		int getGradeS() const;
		int getGradeE() const;
		bool getIsSigned() const;

		void beSigned(const Bureaucrat &b);

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
		bool  _isSigned;
		const int _gradeS;
		const int _gradeE;
};

std::ostream &operator<<(std::ostream &out, const Form &f);

#endif
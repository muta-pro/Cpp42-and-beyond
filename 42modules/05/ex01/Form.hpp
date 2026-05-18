/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 12:45:04 by imutavdz          #+#    #+#             */
/*   Updated: 2026/05/18 13:57:25 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <exceptions>
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
		bool  _isSigned;
		const std::string _name;
		const int _gradeS;
		const int _gradeE;
};

std::ostream &operator<<(std::ostream &out, const Form &f);

#endif
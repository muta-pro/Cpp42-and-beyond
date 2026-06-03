/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 12:45:04 by imutavdz          #+#    #+#             */
/*   Updated: 2026/06/03 12:53:09 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
	public:
		AForm();
		AForm(const std::string &name, const int gradeS, const int gradeE);
		AForm(const AForm &copy);
		AForm &operator=(const AForm &assign);
		virtual ~AForm();

		const std::string	&getName() const;
		int					getGradeS() const;
		int					getGradeE() const;
		bool				getIsSigned() const;

		void	beSigned(const Bureaucrat &b);
		void	execute(const Bureaucrat &executor) const; //new

		class TooHighExc : public std::exception {
		public:
			virtual const char *what() const throw();
		};
		class TooLowExc : public std::exception {
		public:
			virtual const char *what() const throw();
		};
		class AlreadySignedExc : public std::exception {
		public:
			virtual const char *what() const throw();
		};
		class NotSignedExc : public std::exception {
		public:
			virtual const char *what() const throw();
		};

	protected:
		virtual	void beExec(const Bureaucrat &e) const = 0; //pure virtual
		//this is implemented in different subclasses

	private:
		const std::string	_name;
		bool					_isSigned;
		const int			_gradeS;
		const int			_gradeE;
};

std::ostream	&operator<<(std::ostream &out, const AForm &f);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 12:45:04 by imutavdz          #+#    #+#             */
/*   Updated: 2026/06/23 00:22:00 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;//forward decl

class Form {
	public:
		Form() = default;
		Form(const std::string &name, int gradeS, int gradeE);
		Form(const Form &copy) = default;
		Form &operator=(const Form &assign);
		~Form() = default;

		const std::string	&getName() const;
		int					getGradeS() const; //const for const obj call
		int					getGradeE() const;
		bool				getIsSigned() const;

		class TooHighExc : public std::exception {
		public:
			const char *what() const noexcept override;
		};
		class TooLowExc : public std::exception {
		public:
			const char *what() const noexcept override;
		};

		[[nodiscard]] bool	beSigned(const Bureaucrat &b) noexcept;//needs to know about Bureau.
	private:
		bool				_isSigned;
		const std::string	_name;
		const int			_gradeS;
		const int			_gradeE;
};

std::ostream	&operator<<(std::ostream &out, const Form &f);

#endif
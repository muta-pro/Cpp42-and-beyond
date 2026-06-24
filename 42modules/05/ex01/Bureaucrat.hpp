/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 08:49:16 by imutavdz          #+#    #+#             */
/*   Updated: 2026/06/23 00:20:18 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

#include <iostream>
#include <string>
#include <exception>

class Form;

class Bureaucrat {
	public:
			Bureaucrat() = default;
			Bureaucrat(const std::string &name, int grade);
			Bureaucrat(const Bureaucrat &copy) = default;
			Bureaucrat &operator=(const Bureaucrat &assign);
			~Bureaucrat() = default;

			const std::string	&getName() const;
			int					getGrade() const;

			void incGrade();
			void decGrade();
			//exception classes - nested class
			//public means - access level(base methods remain pubblic)
			class TooHighExc : public std::exception {
			public:
				const char *what() const noexcept override;
			};
			class TooLowExc : public std::exception {
			public:
				const char *what() const noexcept override;
			};

			void	signForm(Form &f);//needs to know about Form

			static constexpr int minGrade = 1;
			static constexpr int maxGrade = 150;

	private:
			const std::string	_name;
			int					_grade;
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat& b);

#endif
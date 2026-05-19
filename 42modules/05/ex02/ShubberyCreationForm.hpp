/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShubberyCreationForm.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 23:19:26 by imutavdz          #+#    #+#             */
/*   Updated: 2026/05/19 23:27:17 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCF_HPP
# define SCF_HPP

# include "AForm.hpp"

class ShubberyCreationForm {
	public:
			ShubberyCreationForm();
			ShubberyCreationForm(const std::string &other);
			ShubberyCreationForm(const ShubberyCreationForm &copy);
			ShubberyCreationForm &operator=(const ShubberyCreationForm &assign);
			~ShubberyCreationForm();

			const std::string &getTarget() const;

			void beExec() const;

			static const int gradeS = 145;
			static const int gradeE = 137;
	private:
		std::string 				_target;
		static const std::string	_shubbery;
		static const std::string	_shubberyAlt;
};

#endif
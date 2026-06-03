/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShubberyCreationForm.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 23:19:26 by imutavdz          #+#    #+#             */
/*   Updated: 2026/06/01 08:54:39 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCF_HPP
# define SCF_HPP

# include "AForm.hpp"

class ShubberyCreationForm : public AForm {
	public:
			ShubberyCreationForm();
			ShubberyCreationForm(const std::string &target);
			ShubberyCreationForm(const ShubberyCreationForm &copy);
			ShubberyCreationForm &operator=(const ShubberyCreationForm &assign);
			virtual ~ShubberyCreationForm();

			virtual void	beExec(const Bureaucrat &executor) const;
	private:
		std::string 				_target;
};

#endif
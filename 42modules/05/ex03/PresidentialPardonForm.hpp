/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 13:08:49 by imutavdz          #+#    #+#             */
/*   Updated: 2026/05/30 14:11:41 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PPF_HPP
# define PPF_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	public:
			PresidentialPardonForm();
			PresidentialPardonForm(const std::string &target);
			PresidentialPardonForm(const PresidentialPardonForm &copy);
			PresidentialPardonForm &operator=(const PresidentialPardonForm &assign);
			~PresidentialPardonForm();

			const std::string	&getTarget() const;

			void	beExec(const Bureaucrat &executor) const;
	private:
		std::string	_target;
};

#endif
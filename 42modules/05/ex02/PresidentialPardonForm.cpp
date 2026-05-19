/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 23:19:55 by imutavdz          #+#    #+#             */
/*   Updated: 2026/05/19 23:27:57 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PPF_HPP
# define PPF_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	public:
			PresidentialPardonForm();
			PresidentialPardonForm(const std::string &other);
			PresidentialPardonForm(const PresidentialPardonForm &copy);
			PresidentialPardonForm &operator=(const PresidentialPardonForm &assign);
			~PresidentialPardonForm();

			const std::string &getTarget() const;

			void beExec() const;

			static const int gradeS = 25;
			static const int gradeE = 5;
	private:
		std::string _target;
};

#endif
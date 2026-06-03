/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 23:19:02 by imutavdz          #+#    #+#             */
/*   Updated: 2026/06/01 10:00:40 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RRF_HPP
# define RRF_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	public:
			RobotomyRequestForm();
			RobotomyRequestForm(const std::string &target);
			RobotomyRequestForm(const RobotomyRequestForm &copy);
			RobotomyRequestForm &operator=(const RobotomyRequestForm &assign);
			~RobotomyRequestForm();

			const std::string	&getTarget() const;

			void	beExec(const Bureaucrat &executor) const;
	private:
		std::string	_target;
};

#endif
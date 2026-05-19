/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RoboromyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 23:19:02 by imutavdz          #+#    #+#             */
/*   Updated: 2026/05/19 23:27:44 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RRF_HPP
# define RRF_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	public:
			RobotomyRequestForm();
			RobotomyRequestForm(const std::string &other);
			RobotomyRequestForm(const RobotomyRequestForm &copy);
			RobotomyRequestForm &operator=(const RobotomyRequestForm &assign);
			~RobotomyRequestForm();

			const std::string &getTarget() const;

			void beExec() const;

			static const int gradeS = 72;
			static const int gradeE = 45;
	private:
		std::string	_target;
};

#endif
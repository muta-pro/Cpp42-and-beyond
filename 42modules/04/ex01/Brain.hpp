/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:31:23 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/10 14:23:00 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* 
Encapsulation is a strict rule so if not explicit attrbute is private by default*/
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
	public:
			Brain ();
			Brain (const Brain  &copy);
			Brain  &operator=(const Brain  &assign);
			~Brain ();

			void setIdea(int indx, const std::string &idea);
			std::string getIdea(int indx) const;

	private:
			std::string _ideas[100];
};


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:31:28 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/10 18:18:43 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constrictor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		_ideas[i] = "no idea";
	}
}

Brain::Brain (const Brain &copy) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = copy;
}

Brain &Brain::operator=(const Brain &assign) {
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &assign) {
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = assign._ideas[i];
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

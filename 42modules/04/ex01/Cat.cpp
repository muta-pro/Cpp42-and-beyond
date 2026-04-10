/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:24:52 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/10 18:23:15 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->_type = copy._type;
	this->_brain = new Brain(*copy._brain);
}

Cat &Cat::operator=(const Cat &assign) {
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &assign) {
		this->_type = assign._type;
		*this->_brain = *assign._brain;
	}
	return (*this);
}

Cat::~Cat() {
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "MJAAAUUUUUU" << std::endl;
}

void Cat::setIdea(int indx, const std::string &idea) {
	this->_brain->setIdea(indx, idea);
}

std::string Cat::getIdea(int indx) const {
	std::cout << this->_brain->getIdea(indx) << std::endl;
}

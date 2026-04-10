/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:24:52 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/10 14:02:04 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
for assignment we dereference pointers to copy object's content
using brains operator to copy 100 idea strings*/
#include "Dog.hpp"

Dog::Dog() : Animal() {
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->_type = copy._type;
	this->_brain = new Brain(*copy._brain);
}

Dog &Dog::operator=(const Dog &assign) {
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &assign) {
		this->_type = assign._type;
		*this->_brain = *assign._brain;
	}
	return (*this);
}

Dog::~Dog() {
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "AWAWAWAWAW" << std::endl;
}

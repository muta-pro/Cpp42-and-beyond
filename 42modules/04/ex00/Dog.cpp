/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:24:52 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/07 20:08:36 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	this->_type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = copy;
}

Dog &Dog::operator=(const Dog &assign) {
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &assign)
		this->_type = assign._type;
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

std::string Dog::getType() const {
	return (this->_type);
}

void Dog::makeSound() const {
	std::cout << "AWAWAWAWAW" << std::endl;
}

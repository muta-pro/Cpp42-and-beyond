/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 17:25:15 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/11 14:51:18 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
	std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::Animal(const Animal &copy) {
	std::cout << "Animal copy Constructor called" << std::endl;
	*this = copy;
}

Animal& Animal::operator=(const Animal &assign) {
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &assign)
		_type = assign._type;
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal Destructor called" << std::endl;
}

std::string Animal::getType() const {
	return (this->_type);
}

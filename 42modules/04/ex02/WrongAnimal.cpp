/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:24:52 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/09 18:21:13 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
	std::cout << "WrongAnimal copy Constructor called" << std::endl;
	*this = copy;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &assign) {
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	if (this != &assign)
		_type = assign._type;
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << _type << " makes generic animal sound" << std::endl;
}

std::string WrongAnimal::getType() const {
	return (this->_type);
}

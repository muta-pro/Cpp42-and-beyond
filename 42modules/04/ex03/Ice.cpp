/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 15:35:42 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/11 20:07:24 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice &copy) : AMateria(copy) {
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &assign) {
	std::cout << "Ice Assignment operator called" << std::endl;
	if (this != &assign) {
		AMateria::operator=(assign);
	}
	return (*this);
}

Ice::~Ice() {
	std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone() const {
	std::cout << "Ice clone() called" << std::endl;
	return (new Ice(*this)); //use copy constructor
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

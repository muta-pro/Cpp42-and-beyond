/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 15:35:52 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/12 20:27:56 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(const Cure &copy) : AMateria(copy) {
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &assign) {
	std::cout << "Cure Assignment operator called" << std::endl;
	if (this != &assign) {
		AMateria::operator=(assign);
	}
	return (*this);
}

Cure::~Cure() {
	std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone() const {
	std::cout << "Cure clone() called" << std::endl;
	return (new Cure(*this)); //use copy constructor
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
}

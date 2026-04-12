/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 15:26:05 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/11 20:04:08 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(const std::string &type) : _type(type) {
	std::cout << "AMateria constructor called type: " << _type << std::endl;
}

AMateria::AMateria(const AMateria &copy) : _type(copy._type) {
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &assign) {
	std::cout << "AMateria assigngment operator called" << std::endl;
	if (this != &assign) {}
	return (*this);
}

AMateria::~AMateria() {
	std::cout << "AMateria Destructor called type: " << _type << std::endl;
}

std::string const &AMateria::getType() const {
	return (_type);
}

void AMateria::use(ICharacter& target) {
	(void)target;
}

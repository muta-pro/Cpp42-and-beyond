/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 12:50:56 by imutavdz          #+#    #+#             */
/*   Updated: 2026/03/28 20:53:06 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fpn(0) {
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) : _fpn(copy._fpn) {
	std::cout << "Copy Constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &assign) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &assign) {
		this->_fpn = assign.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destrcutor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fpn);
}

void	Fixed::setRawBits(int const raw) {
	this->_fpn = raw;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 18:25:04 by imutavdz          #+#    #+#             */
/*   Updated: 2026/03/26 18:30:35 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed (void) : _fpn(0) {
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed (const int n) {
	std::cout << "Int constructor called" << std::endl;
		_fpn = n << _fbn;
}

Fixed::Fixed (const float fpn) {
	std::cout << "Float constructor called" << std::endl;
	float scaled = fpn * (1 << _fbn);
		_fpn = static_cast<int>(roundf(scaled));

}

Fixed::Fixed (const Fixed &copy) {
	std::cout << "Copy Constructor called" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &assign) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &assign) {
		this->_fpn = assign.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	return this->_fpn;
}

void	Fixed::setRawBits(int const raw) {
	this->_fpn = raw;
}

float	Fixed::toFloat(void) const {
	return static_cast<float>(_fpn) / (1 << _fbn);
}

int	Fixed::toInt(void) const {
	return _fpn >> _fbn;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

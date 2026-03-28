/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:39:44 by imutavdz          #+#    #+#             */
/*   Updated: 2026/03/28 14:27:59 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed (void) : _fpn(0) {
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed (const int n) {
	std::cout << "Int constructor called" << std::endl;
	// int maxSafeInt = INT_MAX >> _fbn;
	// int minSafeInt = INT_MIN >> _fbn;
	// if (n > maxSafeInt || n < minSafeInt)
	// {
	// 	std::cerr << "WARNING: value " << n << " too large." << std::endl;
	// 	if (n > maxSafeInt)
	// 		_fpn = INT_MAX;
	// 	else
	// 		_fpn = INT_MIN;
	// }
	// else
		_fpn = n << _fbn;
}

Fixed::Fixed (const float fpn) {
	std::cout << "Float constructor called" << std::endl;
	float scaled = fpn * (1 << _fbn);
	// if (scaled > INT_MAX || scaled < INT_MIN)
	// {
	// 	std::cerr << "WARNING: Float value " << fpn << " too large." << std::endl;
	// 	if (scaled > INT_MAX)
	// 		_fpn = INT_MAX;
	// 	else
	// 		_fpn = INT_MIN;
	// }
	// else
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
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	return (this->_fpn);
}

void	Fixed::setRawBits(int const raw) {
	this->_fpn = raw;
}

float	Fixed::toFloat(void) const {
	return (static_cast<float>(_fpn) / (1 << _fbn));
}

int	Fixed::toInt(void) const {
	return (_fpn >> _fbn);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}

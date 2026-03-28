/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 12:17:23 by imutavdz          #+#    #+#             */
/*   Updated: 2026/03/28 14:44:47 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed (void) : _fpn(0) {
	// std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed (const int n) {
	// std::cout << "Int constructor called" << std::endl;
		_fpn = n << _fbn;
}

Fixed::Fixed (const float fpn) {
	// std::cout << "Float constructor called" << std::endl;
	float scaled = fpn * (1 << _fbn);
		_fpn = static_cast<int>(roundf(scaled));

}

Fixed::Fixed (const Fixed &copy) : _fpn(copy._fpn) {
	// std::cout << "Copy Constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &assign) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &assign) {
		this->_fpn = assign.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
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

/* Comparison */

bool	Fixed::operator>(const Fixed &other) const {
	return (this->_fpn > other._fpn);
}

bool	Fixed::operator<(const Fixed &other) const {
	return (this->_fpn < other._fpn);
}

bool	Fixed::operator>=(const Fixed &other) const {
	return (this->_fpn >= other._fpn);
}
bool	Fixed::operator<=(const Fixed &other) const {
	return (this->_fpn <= other._fpn);
}
bool	Fixed::operator==(const Fixed &other) const {
	return (this->_fpn == other._fpn);
}
bool	Fixed::operator!=(const Fixed &other) const {
	return (this->_fpn != other._fpn);
}

/* Arithmetic */

Fixed	Fixed::operator+(const Fixed &other) const {
	Fixed result;
	result.setRawBits(this->_fpn + other._fpn);
	return (result); 
}

Fixed	Fixed::operator-(const Fixed &other) const {
	Fixed result;
	result.setRawBits(this->_fpn - other._fpn);
	return (result);
}

Fixed	Fixed::operator*(const Fixed &other) const {
	Fixed result;
	result.setRawBits((static_cast<long>(this->_fpn) * other._fpn) >> _fbn);
	return (result);
}
Fixed	Fixed::operator/(const Fixed &other) const {
	Fixed result;
	result.setRawBits((static_cast<long>(this->_fpn) << _fbn) / other._fpn);
	return (result);
}

/* Increment/Decrement */

Fixed	&Fixed::operator++() {
	++this->_fpn;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed t(*this);
	this->_fpn++;
	return (t);
}

Fixed	&Fixed::operator--() {
	--this->_fpn;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed t(*this);
	this->_fpn--;
	return (t);
}

/* MIN/MAX */

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return (a);
	else
		return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return (a);
	else
		return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a > b)
		return (a);
	else
		return (b);
}

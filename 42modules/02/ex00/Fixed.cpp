/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 12:50:56 by imutavdz          #+#    #+#             */
/*   Updated: 2026/03/25 14:22:44 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed (int fpn) : fpn = 0 {
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed () {
	std::cout << "Copy Constructor called" << std::endl;
}

Fixed::Fixed () {
	std::cout << "Assignment operator called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destrcutor called" << std::endl;
}

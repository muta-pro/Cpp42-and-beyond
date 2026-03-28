/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 12:16:52 by imutavdz          #+#    #+#             */
/*   Updated: 2026/03/28 14:39:49 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {}

Point::Point(const float n, const float m) : _x(n), _y(m) {}

Point::Point(const Point &copy) : _x(copy._x), _y(copy._y) {}

Point &Point::operator=(const Point &assign) {
	(void)assign;
	return (*this);
}

Point::~Point(void) {}

const Fixed &Point::getX() const {
	return (_x);
}

const Fixed &Point::getY() const {
	return (_y);
}

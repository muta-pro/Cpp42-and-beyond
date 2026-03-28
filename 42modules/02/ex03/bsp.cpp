/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 12:16:55 by imutavdz          #+#    #+#             */
/*   Updated: 2026/03/28 14:37:20 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed sign(Point const a, Point const b, Point const c)
{
	Fixed x1 = a.getX() - c.getX();
	Fixed x2 = b.getX() - c.getX();
	Fixed y1 = a.getY() - c.getY();
	Fixed y2 = b.getY() - c.getY();
	Fixed result = (x1 * y2) - (x2 * y1); 

	return (result);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed A;
	Fixed B;
	Fixed C;
	bool AllPositive;
	bool AllNegative;

	A = sign(point, a, b);
	B = sign(point, b, c);
	C = sign(point, c, a);

	AllNegative = (A < Fixed(0) && B < Fixed(0) && C < Fixed(0));
	AllPositive = (A > Fixed(0) && B > Fixed(0) && C > Fixed(0));

	return (AllPositive || AllNegative);
}
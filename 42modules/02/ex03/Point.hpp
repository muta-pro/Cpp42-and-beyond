/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 12:16:53 by imutavdz          #+#    #+#             */
/*   Updated: 2026/03/28 14:39:17 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP value

#include <cmath>
#include "Fixed.hpp"

class Point{
	public:
			Point();
			Point(const float n, const float m);
			Point(const Point &src);
			Point &operator=(const Point &assign);
			~Point();
			
			const Fixed &getX() const;
			const Fixed &getY() const;
	
	private:
		const Fixed _x;
		const Fixed _y;

};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif

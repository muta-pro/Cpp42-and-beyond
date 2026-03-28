/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:39:51 by imutavdz          #+#    #+#             */
/*   Updated: 2026/03/28 01:48:34 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
// #include <climits>


class Fixed
{
public:
	Fixed();
	Fixed(const int n);
	Fixed(const float fpn);
	Fixed(const Fixed &copy);
	Fixed &operator=(const Fixed &assign);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

private:
	int					_fpn;//fixed-point number
	static const int	_fbn = 8;//number of fractional bits:rule that
									//the last 8 bits are the fractoin
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif

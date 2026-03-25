/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 12:50:40 by imutavdz          #+#    #+#             */
/*   Updated: 2026/03/25 13:11:02 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed(int fpn);
	Fixed();
	=operator();
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int fpn;
	static const int fbn = 8;
};

#endif

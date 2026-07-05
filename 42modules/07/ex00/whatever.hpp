/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 17:06:57 by imutavdz          #+#    #+#             */
/*   Updated: 2026/07/03 14:03:55 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP


#include <string>
#include <iostream>

template <typename T>
void swap(T& a, T& b) {
	T temp = (std::move(a));
	a = std::move(b);
	b = std::move(temp);
}

template <typename T>
const T& min(const T& a, const T& b) {
	if (a < b)
		return a;
	else
		return b;
}

template <typename T>
const T& max(const T& a, const T& b) {
	if (a > b)
		return a;
	else
		return b;
}

#endif
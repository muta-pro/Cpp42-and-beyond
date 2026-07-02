/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 17:06:57 by imutavdz          #+#    #+#             */
/*   Updated: 2026/07/01 18:33:09 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP


#include <string>
#include <iostream>
#include <.h>

template <typename T>
void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
const T& min(T& a, T& b) {
	if (a < b)
		return a;
	else
		return b;
}

template <typename T>
const T& max(T& a, T& b) {
	if (a > b)
		return a;
	else
		return b;
}

#endif
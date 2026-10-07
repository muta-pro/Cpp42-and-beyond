/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 17:46:16 by imutavdz          #+#    #+#             */
/*   Updated: 2026/10/07 15:55:59 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& cont, int n) {
	typename T::iterator it = std::find(cont.begin(), cont.end(), n);
	if (it == cont.end()) {
		throw std::exception();
	}
	return it;
}
template <typename T>
typename T::const_iterator easyfind(const T& cont, int n) {
	typename T::iterator it = std::find(cont.begin(), cont.end(), n);
	if (it == cont.end()) {
		throw std::exception();
	}
	return it;
}

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 17:46:16 by imutavdz          #+#    #+#             */
/*   Updated: 2026/10/07 16:31:09 by imutavdz         ###   ########.fr       */
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
	typename T::const_iterator it = std::find(cont.begin(), cont.end(), n);
	if (it == cont.end()) {
		throw std::exception();
	}
	return it;
}

#endif

/*same as saying
std::vector<int>::const_iterator easyfind(const std::vector<int>& cont, int n);
*/
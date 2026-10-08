/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 17:46:16 by imutavdz          #+#    #+#             */
/*   Updated: 2026/10/08 17:55:16 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
auto easyfind(T& cont, int n) {
	auto it = std::find(cont.begin(), cont.end(), n);
	if (it == cont.end()) {
		throw std::exception();
	}
	return it;
}
template <typename T>
auto easyfind(const T& cont, int n) {
	auto it = std::find(cont.begin(), cont.end(), n);
	if (it == cont.end()) {
		throw std::exception();
	}
	return it;
}

#endif

/*same as saying
std::vector<int>::const_iterator easyfind(const std::vector<int>& cont, int n);
*/
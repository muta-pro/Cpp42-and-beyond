/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 19:08:56 by imutavdz          #+#    #+#             */
/*   Updated: 2026/08/28 18:42:56 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
	Span span1(100);

	std::vector<int> vec = {1, 2, 3};
	span1.AddNumbers(vec.begin(), vec.end());

	std::list<int> lst = {33, 44, 55};
	span1.AddNumbers(vec.begin(), vec.end());

	std::set<int> st = {4, 5};
	span1.AddNumbers(st.begin(), st.end());
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 19:08:56 by imutavdz          #+#    #+#             */
/*   Updated: 2026/10/09 00:08:37 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <set>
#include <cstdlib>
#include <list>
#include <vector>
#include <algorithm>

int main() {
	Span span1(100);

	std::vector<int> vec = {1, 2, 3};
	span1.AddRange(vec.begin(), vec.end());

	std::list<int> lst = {33, 44, 55};
	span1.AddRange(lst.begin(), lst.end());

	std::set<int> st = {4, 5};
	span1.AddRange(st.begin(), st.end());

	Span bigSpan(10000);
	std::vector<int> randNum(10000);

	std::generate(randNum.begin(), randNum.end(), std::rand);
	try {
		bigSpan.AddRange(randNum.begin(), randNum.end());
		std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
		std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	Span emptyspan();

	std::vector<int> v = {1, 5.5};
	v.AddRange(v.begin(), v.end());


	return 0;
}
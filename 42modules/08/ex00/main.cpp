/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 17:46:00 by imutavdz          #+#    #+#             */
/*   Updated: 2026/08/22 19:06:19 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <array>
#include "easyfind.hpp"

int main() {
	std::vector<int> vec = {10, 20, 30};

	try {
		auto it = easyfind(vec, 10);
		std::cout << "found: " << *it << std::endl;
	} catch (const std::exception &e) {
		std::cout << "number not found" << std::endl;
	}

	try {
		auto it = easyfind(vec, 22);
		std::cout << "found: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << "number 22 not found" << std::endl;
	}

	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(15);
	lst.push_back(115);

	try {
		auto lst_it = easyfind(lst, 5);
		std::cout << "found: " << *lst_it << std::endl;
	} catch (const std::exception &e) {
		std::cout << "number not found" << std::endl;
	}

	try {
		auto lst_it = easyfind(lst, 22);
		std::cout << "found: " << *lst_it << std::endl;
	} catch (std::exception &e) {
		std::cout << "number 22 not found" << std::endl;
	}

	std::deque<int> dq;
	dq.push_back(29);
	dq.push_front(10);
	dq.push_back(11);

	try {
		auto dq_it = easyfind(dq, 29);
		std::cout << "found: " << *dq_it << std::endl;
	} catch (const std::exception &e) {
		std::cout << "number not found" << std::endl;
	}

	try {
		auto dq_it = easyfind(dq, 10);
		std::cout << "found: " << *dq_it << std::endl;
	} catch (std::exception &e) {
		std::cout << "number not found" << std::endl;
	}

	std::array<int, 4> arr_cont = {0, 40, 42, 100};

	try {
		auto arr_it = easyfind(arr_cont, 42);
		std::cout << "found: " << *arr_it << std::endl;
	} catch (std::exception &e) {
		std::cout << "number not found" << std::endl;
	}

	return 0;
}
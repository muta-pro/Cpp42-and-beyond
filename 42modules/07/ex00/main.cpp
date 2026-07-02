/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 17:06:44 by imutavdz          #+#    #+#             */
/*   Updated: 2026/07/01 18:35:45 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main()
{
	int a = 5;
	int b = 10;

	::swap(a, b);
	std::cout << "a = " << a << ". b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "mac(a, b) = " << ::max(a, b) << std::endl; 

	std::string c = "whatever1";
	std::string d = "whatever2";

	::swap(a, b);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "mac(c, d) = " << ::max(c, d) << std::endl;

	return 0;	
}
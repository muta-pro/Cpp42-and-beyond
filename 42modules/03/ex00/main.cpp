/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:27:12 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/03 16:54:06 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	std::cout << "*construction*" << std::endl;
	ClapTrap def;
	ClapTrap bob("Bob");
	ClapTrap bobCopy(bob);

	std::cout << "\n*assignment*" << std::endl;
	def = bob;

	std::cout << "\n*attack*" << std::endl;
	bob.attack("Alice");
	bob.attack("Alice");

	std::cout << "\n*take damage*" << std::endl;
	bob.takeDamage(5);
	bob.takeDamage(10);

	std::cout << "\n*repair fail:dead*" << std::endl;
	bob.beRepaired(5);

	std::cout << "\n*repair fresh*" << std::endl;
	ClapTrap alice("Alice");
	alice.beRepaired(3);

	std::cout << "\n*drain energy*" << std::endl;
	ClapTrap drain("Drainer");
	for (int i = 0; i < 10; i++)
		drain.attack("Bob");
	drain.attack("Bob");

	std::cout << "\nDestruction" << std::endl;
	return (0);
}

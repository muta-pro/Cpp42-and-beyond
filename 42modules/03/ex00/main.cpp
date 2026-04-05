/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:27:12 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/05 13:47:31 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	std::cout << "* CONSTRUCTION *" << std::endl;
	ClapTrap def;
	ClapTrap bob("Bob");
	ClapTrap bobCopy(bob);

	std::cout << "\n* ASSIGN *" << std::endl;
	def = bob;

	std::cout << "\n* ATTACK *" << std::endl;
	bob.attack("Alice");
	bob.attack("Alice");

	std::cout << "\n* TAKE DAMAGE *" << std::endl;
	bob.takeDamage(5);
	bob.takeDamage(10);

	std::cout << "\n* REPAIR FAIL *" << std::endl;
	bob.beRepaired(5);

	std::cout << "\n* REPAIR FRESH *" << std::endl;
	ClapTrap alice("Alice");
	alice.beRepaired(3);

	std::cout << "\n* DRAIN ENERGY *" << std::endl;
	ClapTrap drain("Drainer");
	for (int i = 0; i < 10; i++)
		drain.attack("Bob");
	drain.attack("Bob");

	std::cout << "\n DESTRUCTION " << std::endl;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 17:39:27 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/07 15:00:39 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

int main() {
	std::cout << "\n* DIAMONDTRAP *" << std::endl;
	DiamondTrap bot("Neo");
	bot.WhoAmI();
	bot.attack("Smith");
	bot.takeDamage(20);
	bot.beRepaired(5);

	std::cout << "\n* COPY *" << std::endl;
	DiamondTrap copy(bot);
	DiamondTrap assign;
	assign = bot;
	assign.WhoAmI();

	std::cout << "\n* LEAVING SCOPE *" << std::endl;

	return (0);
}

// int main(void)
// {
// 	std::cout << "=== Module 03 Exercise 03: DiamondTrap Test ===" << std::endl;

// 	std::cout << "\n--- Construction Chaining Test ---" << std::endl;
// 	DiamondTrap diamond("Hero");

// 	std::cout << "\n--- Name Identity Test ---" << std::endl;
// 	diamond.WhoAmI();

// 	std::cout << "\n--- Inherited Functions Test ---" << std::endl;
// 	diamond.attack("Enemy");           // Should use ScavTrap's attack
// 	diamond.takeDamage(25);            // From ClapTrap
// 	diamond.beRepaired(10);            // From ClapTrap

// 	std::cout << "\n--- Special Abilities Test ---" << std::endl;
// 	diamond.guardGate();               // From ScavTrap
// 	diamond.highFiveGuys();           // From FragTrap

// 	std::cout << "\n--- Attributes Test ---" << std::endl;
// 	std::cout << "Expected stats:" << std::endl;
// 	std::cout << "- Hit Points: 100 (from FragTrap)" << std::endl;
// 	std::cout << "- Energy Points: 50 (from ScavTrap)" << std::endl;
// 	std::cout << "- Attack Damage: 30 (from FragTrap)" << std::endl;
// 	std::cout << "- Attack function: from ScavTrap" << std::endl;

// 	std::cout << "\n--- Copy Constructor Test ---" << std::endl;
// 	{
// 		DiamondTrap copy(diamond);
// 		copy.WhoAmI();
// 	}

// 	std::cout << "\n--- Assignment Operator Test ---" << std::endl;
// 	DiamondTrap assigned("Assigned");
// 	assigned = diamond;
// 	assigned.WhoAmI();

// 	std::cout << "\n--- Edge Case: Multiple Inheritance Test ---" << std::endl;
// 	DiamondTrap multi("Multi");

// 	// Test that we only have one ClapTrap instance
// 	multi.attack("TestTarget");
// 	multi.guardGate();
// 	multi.highFiveGuys();
// 	multi.WhoAmI();

// 	std::cout << "\n--- Destruction Chaining Test ---" << std::endl;
// 	return 0;
// }

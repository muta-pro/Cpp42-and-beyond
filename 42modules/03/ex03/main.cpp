/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 17:39:27 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/04 19:04:13 by imutavdz         ###   ########.fr       */
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
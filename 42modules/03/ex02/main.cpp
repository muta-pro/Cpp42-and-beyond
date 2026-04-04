/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 16:04:40 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/04 17:35:27 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	std::cout << "\n* CLAPTRAP *" << std::endl;
	ClapTrap base("Kurosawa");
	base.attack("target");
	base.takeDamage(3);
	base.beRepaired(1);

	std::cout << "\n* SCAVTRAP *" << std::endl;
	ScavTrap guard("Poll");
	guard.attack("enemy");
	guard.takeDamage(15);
	guard.beRepaired(5);
	guard.guardGate();

	std::cout << "\n* FRAGTRAP *" << std::endl;
	FragTrap frog("wth");
	frog.attack("spider");
	frog.takeDamage(50);
	frog.beRepaired(7);
	frog.highFiveGives();

	FragTrap copy(frog);
	FragTrap assign;
	assign = frog;

	std::cout << "\n* LEAVING SCOPE *" << std::endl;

	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 21:27:16 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/05 13:48:07 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	std::cout << "* CLAPTRAP *" << std::endl;
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

	ScavTrap copy(guard);
	ScavTrap assign;
	assign = guard;

	std::cout << "\n* LEAVING SCOPE *" << std::endl;
	return (0);
}
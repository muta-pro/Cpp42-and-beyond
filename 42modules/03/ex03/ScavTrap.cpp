/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 17:39:47 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/05 15:35:56 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("default") {

	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &assign) {
	std::cout << "ScavTrap Assignment operator called" << std::endl;
	if (this != &assign)
		ClapTrap::operator=(assign);
	return (*this);
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	std::cout << "ScavTrap name Constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout <<  "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	if (_HitPoints <= 0 || _EnergyPoints <= 0) {
		std::cout << "ScavTrap " << _Name << " can't attack without points" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _Name << " attacks " << target << " depriving points:"
				<< _AttackDamage << std::endl;
	_EnergyPoints--;
 }

void ScavTrap::guardGate() {
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

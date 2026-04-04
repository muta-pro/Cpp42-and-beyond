/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 17:40:26 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/04 19:18:05 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("def_clap_name"),
				ScavTrap(), FragTrap(), _Name("default") {
	std::cout << "DiamondTrap default Constructor called" << std::endl;
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy.ClapTrap::_Name),
				ScavTrap(copy), FragTrap(copy), _Name(copy._Name) {
	std::cout << "DiamondTrap copy Constructor called" << std::endl;
	_HitPoints = copy._HitPoints;
	_EnergyPoints = copy._EnergyPoints;
	_AttackDamage = copy._AttackDamage;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &assign) {
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	if (this != &assign)
	{
		ClapTrap::operator=(assign);
		_Name = assign._Name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "+_clap_name"),
				ScavTrap(name), FragTrap(name), _Name(name) {
	std::cout << "DiamondTrap default Constructor called" << std::endl;
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 30;
}

void DiamondTrap::attack(const std::string &target) {
	if (_HitPoints <= 0 || _EnergyPoints <= 0) {
		std::cout << "DiamondTrap" << _Name << "can't attack without points" << std::endl;
		return ;
	}
	std::cout << "DiamondTrap " << _Name << " attacks "
		 << target << " causing " << _AttackDamage << " points damage" << std::endl;
	_EnergyPoints--; 
}

void DiamondTrap::WhoAmI() {
	std::cout << "DiamondTrap name is " << _Name << " and ClapTrap name is "
				<< ClapTrap::_Name << std::endl;
}

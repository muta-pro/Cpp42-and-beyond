/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:43:36 by imutavdz          #+#    #+#             */
/*   Updated: 2026/03/31 14:26:28 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &assign) {
	if (this != &assign) {
		_Name = assign._Name;
		HitPoints = assign.HitPoints;
		EnergyPoints = assign.EnergyPoints;
		AttackDamage = assign.AttackDamage;
	}
	return (*this);
}

ClapTrap::ClapTrap(const std::string &name) {}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	std::cout << _Name << "attacks" << target << "loosing points:" << AttackDamage;  
	AttackDamage = EnergyPoints--;
}
void ClapTrap::takeDamage(unsigned int amount) {
	HitPoints -= amount;
	if (HitPoints < 0)
		HitPoints = 0;

}
void ClapTrap::beRepaired(unsigned int amount) {
	HitPoints += amount;
	EnergyPoints--;
}
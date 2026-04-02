/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:43:36 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/01 19:29:57 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
: _Name("default"), _HitPoints(0), _EnergyPoints(0), _AttackDamage(0) {
	std::cout << "Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	std::cout << "Copy Constructor called" << std::endl;
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &assign) {
	if (this != &assign) {
		_Name = assign._Name;
		_HitPoints = assign._HitPoints;
		_EnergyPoints = assign._EnergyPoints;
		_AttackDamage = assign._AttackDamage;
	}
	return (*this);
}

ClapTrap::ClapTrap(const std::string &name)
: _Name("default"), _HitPoints(0), _EnergyPoints(0), _AttackDamage(0) {
	std::cout << "Name Constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (_HitPoints <= 0) {
		std::cout << "ClapTrap" << _Name << "can't attack without points" << std::endl;
	}
	std::cout << _Name << "attacks" << target << "loosing points:" << _AttackDamage;  
	_AttackDamage = _EnergyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << _Name << "got damage" << std::endl;
	_HitPoints -= amount;
	if (_HitPoints < 0)
		_HitPoints = 0;

}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_HitPoints <= 0) {
		std::cout << _Name << "can't repair, not enough hitpoints" << std::endl;
		return ;
	}
	if (_EnergyPoints <= 0) {
		std::cout << _Name << "can't repair, not enough energy points" << std::endl;
		return ;
	}
	_EnergyPoints--;
	_HitPoints += amount;
	std::cout << "ClapTrap" << _Name << "got repaired with amount" << amount
		<< "hitpoints, with total of" << _HitPoints << std::endl;
}

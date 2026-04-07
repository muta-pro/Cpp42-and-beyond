/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 17:39:35 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/07 02:20:08 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
: _Name("default"), _HitPoints(10), _EnergyPoints(10), _AttackDamage(10) {
	std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) : _Name(copy._Name), _HitPoints(copy._HitPoints),
_EnergyPoints(copy._EnergyPoints), _AttackDamage(copy._AttackDamage) {
	std::cout << "ClapTrap Copy Constructor called " << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &assign) {
	std::cout << "ClapTrap Assignment operator called" << std::endl;
	if (this != &assign) {
		_Name = assign._Name;
		_HitPoints = assign._HitPoints;
		_EnergyPoints = assign._EnergyPoints;
		_AttackDamage = assign._AttackDamage;
	}
	return (*this);
}

ClapTrap::ClapTrap(const std::string &name)
: _Name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0) {
	std::cout << "ClapTrap Name Constructor called " << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Destructor called " << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (_HitPoints <= 0 || _EnergyPoints <= 0) {
		std::cout << "ClapTrap " << _Name << " can't attack without points" << std::endl;
		return ;
	}
	_EnergyPoints--;
	std::cout << "ClapTrap" << _Name << " attacks " << target << " depriving points:" 
				<< _AttackDamage << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << _Name << " got damage" << std::endl;
	if ((int)amount >=_HitPoints)
		_HitPoints = 0;
	else
		_HitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_HitPoints <= 0) {
		std::cout << "ClapTrap" << _Name << " can't repair, not enough hitpoints " << std::endl;
		return ;
	}
	if (_EnergyPoints <= 0) {
		std::cout << "ClapTrap" << _Name << " can't repair, not enough energy points " << std::endl;
		return ;
	}
	_EnergyPoints--;
	_HitPoints += amount;
	std::cout << "ClapTrap " << _Name << " got repaired with amount "
				<< amount << " hitpoints, with total of " << _HitPoints << std::endl;
}

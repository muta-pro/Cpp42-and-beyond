/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:43:36 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/05 13:24:18 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
: _Name("default"), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0) {
	std::cout << "Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	std::cout << "Copy Constructor called " << std::endl;
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &assign) {
	std::cout << "Assignment operator called" << std::endl;
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
	std::cout << "Name Constructor called " << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called " << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (_HitPoints <= 0 || _EnergyPoints <=0) {
		std::cout << _Name << " can't attack without points \n"
					 << std::endl;
		return ;
	}
	_EnergyPoints--;
	std::cout << _Name << " attacks " << target << " depriving points:" 
				<< _AttackDamage << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << _Name << " got damage" << std::endl;
	if ((int)amount >= _HitPoints)
		_HitPoints = 0;
	else
		_HitPoints -= amount;

}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_HitPoints <= 0) {
		std::cout << _Name << " can't repair, not enough hitpoints " << std::endl;
		return ;
	}
	if (_EnergyPoints <= 0) {
		std::cout << _Name << " can't repair, not enough energy points " << std::endl;
		return ;
	}
	_EnergyPoints--;
	_HitPoints += amount;
	std::cout << _Name << " got repaired with amount " << amount
				<< " hitpoints, with total of " << _HitPoints << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 17:39:59 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/07 02:27:07 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
In C++, a member is "odr-used" (One Definition Rule-used) if it is
named in a potentially-evaluated expression,
requiring its definition to exist in the program
*/
#include "FragTrap.hpp"

const int FragTrap::C_HitPoints;
const int FragTrap::C_EnergyPoints;
const int FragTrap::C_AttackDamage;

FragTrap::FragTrap() : ClapTrap("default") {
	std::cout << "FragTrap Default Constructor called" << std::endl;
	_HitPoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) {
	std::cout << "FragTrap Copy Constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &assign) {
	std::cout << "FragTrap assignment operator called" << std::endl;
	if (this != &assign)
		ClapTrap::operator=(assign);
	return (*this);
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	std::cout << "FragTrap Name Constructor called" << std::endl;
	_HitPoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::highFiveGuys() {
	std::cout << "FragTrap" << _Name << "requests high five" << std::endl;
}

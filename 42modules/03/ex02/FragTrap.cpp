/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 17:02:15 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/04 17:49:28 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("default") {
	std::cout << "FragTrap Default Constructor called" << std::endl;
	_HitPoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) {
	std::cout << "FragTrap copy Constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &assign) {
	std::cout << "FragTrap assignment operator called" << std::endl;
	if (this != &assign)
		ClapTrap::operator=(assign);
	return (*this);
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	std::cout << "FragTrap Default name Constructor called" << std::endl;
	_HitPoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::highFiveGives() {
	std::cout << "FragTrap" << _Name << "requests high five" << std::endl;
}


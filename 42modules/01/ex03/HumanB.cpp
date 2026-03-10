/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 10:16:55 by imutavdz          #+#    #+#             */
/*   Updated: 2026/03/10 13:04:58 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name) : _name(name), _weapon(nullptr) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& weapon)
{ _weapon = &weapon; }

void HumanB::attack() const
{
	if(!_weapon)
		std::cout << "has no weapon" << std::endl;
	else
		std::cout << _name << "attacks with their" << _weapon->getType() << std::endl;
}

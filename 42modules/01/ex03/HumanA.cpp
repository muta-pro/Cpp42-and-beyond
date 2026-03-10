/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 10:16:48 by imutavdz          #+#    #+#             */
/*   Updated: 2026/03/10 13:02:30 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon) 
	: _name(name), _weapon(weapon) {}

HumanA::~HumanA() {}

void HumanA::attack() const
{
	std::cout << _name << "attacks with their" << _weapon.getType() << std::endl;
}

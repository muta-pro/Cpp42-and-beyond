/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 10:17:00 by imutavdz          #+#    #+#             */
/*   Updated: 2026/03/10 12:57:29 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>
#pragma once

class HumanB
{
public:
	HumanB(const std::string& name);
	~HumanB();
	void setWeapon(Weapon& weapon);
	void attack() const;

private:
	std::string _name;
	Weapon* _Weapon;
};

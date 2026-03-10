/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 10:16:45 by imutavdz          #+#    #+#             */
/*   Updated: 2026/03/10 13:03:19 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"
#pragma once

class HumanA
{
public:
	HumanA(const std::string& name, Weapon& weapon);
	~HumanA();
	void attack() const;

private:
	std::string _name;
	Weapon& _weapon;
};
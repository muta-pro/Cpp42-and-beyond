/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 17:40:02 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/07 02:30:21 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 /* clas-level stat-profile constats:
 static const expresses beloning to a specific class profile values (constant)
 not per-obj  mutable values runtime state in general
 alternative would be protected static gettervalues methods.
 */
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap {
	public:
			FragTrap();
			FragTrap(const std::string &name);
			FragTrap(const FragTrap &copy);
			FragTrap &operator=(const FragTrap &assign);
			~FragTrap();

			void highFiveGuys();
	protected:
		static const int C_HitPoints = 100;
		static const int C_EnergyPoints = 100;
		static const int C_AttackDamage = 30;
};

#endif

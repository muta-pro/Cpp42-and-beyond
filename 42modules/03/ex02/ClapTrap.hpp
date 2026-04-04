/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 17:05:06 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/04 17:05:12 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ClapTrap_HPP
#define ClapTrap_HPP

#include <iostream>
#include <string>

class ClapTrap{
	public:
			ClapTrap();
			ClapTrap(const std::string &name);
			ClapTrap(const ClapTrap &copy);
			ClapTrap &operator=(const ClapTrap &assign);
			~ClapTrap();

			void attack(const std::string &target);
			void takeDamage(unsigned int amount);
			void beRepaired(unsigned int amount);
	protected:
		std::string	_Name;
		int			_HitPoints;
		int			_EnergyPoints;
		int			_AttackDamage;
};

#endif

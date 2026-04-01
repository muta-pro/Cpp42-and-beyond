/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:43:33 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/01 19:03:18 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

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
	private:
		std::string	_Name;
		int			_HitPoints;
		int			_EnergyPoints;
		int			_AttackDamage;
};

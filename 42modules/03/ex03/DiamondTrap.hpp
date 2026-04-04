/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 17:40:29 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/04 19:03:57 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	public:
			DiamondTrap();
			DiamondTrap(const std::string &name);
			DiamondTrap(const DiamondTrap &copy);
			DiamondTrap &operator=(const DiamondTrap &assign);
			~DiamondTrap();

			void  attack(const std::string &target);
			void WhoAmI();
	private:
		std::string _Name;

};

#endif
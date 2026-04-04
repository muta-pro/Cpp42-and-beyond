/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 17:39:49 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/04 18:44:06 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	public:
			ScavTrap();
			ScavTrap(const std::string &name);
			ScavTrap(const ScavTrap &copy);
			ScavTrap &operator=(const ScavTrap &assign);
			~ScavTrap();

			void attack(const std::string &target);
			void guardGate();
};

#endif
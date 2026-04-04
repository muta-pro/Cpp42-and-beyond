/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 17:02:15 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/04 17:05:43 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
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
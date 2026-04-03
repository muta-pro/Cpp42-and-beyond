/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 21:29:22 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/03 23:13:57 by imutavdz         ###   ########.fr       */
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 17:02:15 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/04 17:35:54 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap : public ClapTrap {
	public:
			FragTrap();
			FragTrap(const std::string &name);
			FragTrap(const FragTrap &copy);
			FragTrap &operator=(const FragTrap &assign);
			~FragTrap();

			void highFiveGives(void);
};

#endif
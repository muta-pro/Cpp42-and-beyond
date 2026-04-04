/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 17:40:02 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/04 18:44:14 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

			void highFiveGives(void);
};

#endif
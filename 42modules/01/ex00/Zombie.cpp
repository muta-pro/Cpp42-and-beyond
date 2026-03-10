/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 21:02:58 by imutavdz          #+#    #+#             */
/*   Updated: 2026/03/10 06:54:21 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {}

Zombie::~Zombie() {
	std::cout << _name << "is destroyed" << std::endl;
}

void Zombie::announce(void)
{
	std::cout  <<_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

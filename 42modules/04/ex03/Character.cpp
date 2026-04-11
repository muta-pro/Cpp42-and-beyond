/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 16:18:09 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/11 20:20:50 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string &name) : _name(name) {
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;
}

Character::Character(const Character &copy) : _name(copy._name) {
	for (int i = 0; i < 4; i++)
	{
		if (copy._inventory[i])
			_inventory[i] = copy._inventory[i]->clone();
		else
			_inventory[i] = 0;
	}
}

Character &Character::operator=(const Character &assign) {
	if (this != &assign)
	{
		_name = assign._name;
		for (int i = 0; i < 4; i++) {
			delete _inventory[i];
			_inventory[i] = 0;
			if (assign._inventory[i])
				_inventory[i] = assign._inventory[i]->clone();
		}
	}
	return (*this);
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
}

std::string const &Character::getName() const {
	return (_name);
}

void Character::equip(AMateria *m) {
	(void)m;
}

void unequip(int idx) {
	(void)idx;
}

void use(int idx, ICharacter& target) {
	(void)idx; (void)target;
}
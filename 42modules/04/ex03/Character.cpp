/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 16:18:09 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/12 15:23:33 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string &name) : _name(name) {
	for (int i = 0; i < 4; i++) //init all slots to NULL
		_inventory[i] = NULL;
	std::cout << "Character" << _name << " created" << std::endl;
}

Character::Character(const Character &copy) : _name(copy._name) {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < 4; i++) //deep copy - clone each materia
	{
		if (copy._inventory[i] != NULL)
			_inventory[i] = copy._inventory[i]->clone();
	}
	std::cout << "Character copy contructor called" << std::endl;
}

Character &Character::operator=(const Character &assign) {
	std::cout << "Character assignment operator called" << std::endl;
	if (this != &assign)
	{
		_name = assign._name;
		for (int i = 0; i < 4; i++) { //delete old materia first, pervent leaks
			delete _inventory[i];
			_inventory[i] = 0;
			if (assign._inventory[i] != NULL)
				_inventory[i] = assign._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return (*this);
}

Character::~Character() {
	std::cout << "Character " << _name << " destroyed" << std::endl;
	for (int i = 0; i < 4; i++) {
		delete _inventory[i];
		_inventory[i] = NULL;
	}
}

std::string const &Character::getName() const {
	return (_name);
}

void Character::equip(AMateria *m) {
	if (m == NULL) {
		std::cout << _name << " cannot equip NULL matera" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++) { //find empty slot
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			std::cout << _name << " equipped" << m->getType() << " in slot" << i << std::endl;
			return ;
		}
	}
	std::cout << _name << "'s inventoy is full, cannot equip" << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4) {
		std::cout << _name << " cannot unequip: invalid slot" << std::endl;
		return ;
	}
	if (_inventory[idx] == NULL) {
		std::cout << _name << " cannot unequip: empty slot" << std::endl;
		return ;
	}
	//materia stays -caller must save the address and manage memory
	std::cout << _name << " unequiped" << _inventory[idx]->getType() << " slot " << idx << std::endl;
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4) {
		std::cout << _name << " cannot use: invalid slot" << std::endl;
		return ;
	}
	if (_inventory[idx] == NULL) {
		std::cout << "Cannot use empty slot" << std::endl;
		return ;
	}
	_inventory[idx]->use(target); //use materia on target
}
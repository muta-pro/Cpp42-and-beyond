/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 15:24:39 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/12 20:27:23 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		_templates[i] = NULL;
	std::cout << "MateriaSource created" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy) {
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_templates[i] = NULL;
	for (int i = 0; i < 4; i++) {
		if (copy._templates[i] != NULL)
			_templates[i] = copy._templates[i]->clone();
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &assign) {
	std::cout << "MateriaSource assignment operator called" << std::endl;
	if (this != & assign)
		_clearTempl();
	for (int i = 0; i < 4; i++) {
		if (assign._templates[i] != NULL)
			_templates[i] = assign._templates[i]->clone();
		else
			_templates[i] = NULL;
	}
	return (*this);
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource destroyed" << std::endl;
	_clearTempl();
}

void MateriaSource::_clearTempl() {
	for (int i = 0; i < 4; i++) {
		if (_templates[i] != NULL)
			delete _templates[i];
		_templates[i] = NULL;
	}
}

void MateriaSource::learnMateria(AMateria* m) {
	if (m == NULL)
		return ;
	for (int i = 0; i < 4; i++) {
		if (_templates[i] == NULL) {
			_templates[i] = m;
		std::cout << "Learned " << m->getType() << " materia" << std::endl;
			return ;
		}
	}
	std::cout << "Materia is full, cannot learn" << m->getType() << std::endl;
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (_templates[i] != NULL && _templates[i] -> getType() == type) {
			std::cout << "Creating " << type << " from template" << std::endl;
			return (_templates[i]->clone());
		}
	}
	std::cout << "Unknown type " << type << std::endl;
	return (NULL);
}
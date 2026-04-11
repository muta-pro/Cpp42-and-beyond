/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 16:14:39 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/11 20:20:48 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
	public:
			Character(std::string const & name);
			Character(const Character &copy);
			Character &operator=(const Character &assign);
			virtual ~Character();

			virtual std::string const & getName() const;
			virtual void equip(AMateria* m);
			virtual void unequip(int idx);
			virtual void use(int idx, ICharacter& target);
	private:
		std::string _name;
		AMateria* _inventory[4];
};

#endif
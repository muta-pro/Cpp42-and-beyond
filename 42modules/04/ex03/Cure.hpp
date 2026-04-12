/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 15:35:55 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/11 20:10:06 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
	public:
			Cure();
			Cure(const Cure  &copy);
			Cure &operator=(const Cure  &assign);
			~Cure();

			virtual AMateria* clone() const;
			virtual void use(ICharacter& target);
};

#endif
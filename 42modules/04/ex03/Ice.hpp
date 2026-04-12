/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 15:35:45 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/11 20:09:51 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
	public:
			Ice();
			Ice(const Ice &copy);
			Ice &operator=(const Ice &assign);
			virtual ~Ice();

			virtual AMateria* clone() const;
			virtual void use(ICharacter& target);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 15:26:07 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/11 20:10:14 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class AMateria {
	public:
			AMateria (std::string const &type);
			AMateria (const AMateria  &copy);
			AMateria  &operator=(const AMateria  &assign);
			virtual ~AMateria ();

			std::string const & getType() const;
			virtual AMateria* clone() const = 0; //prototype pattern
			virtual void use(ICharacter& target);
	protected:
		std::string _type;

};

#endif
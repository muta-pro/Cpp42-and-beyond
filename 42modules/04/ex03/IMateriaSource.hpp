/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Imateriasource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 15:24:21 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/12 15:52:05 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 #ifndef IMATERIASOURCE_HPP
 #define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource {
	public:
			virtual ~IMateriaSource() {}

			virtual void learnMateria(AMateria* m) = 0;
			virtual AMateria* createMateria(std::string const & type) = 0;
};

 #endif
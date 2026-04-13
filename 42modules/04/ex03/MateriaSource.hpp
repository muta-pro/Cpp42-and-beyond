/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 15:24:36 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/12 20:11:45 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	public:
			MateriaSource();
			MateriaSource(const MateriaSource &copy);
			MateriaSource &operator=(const MateriaSource &assign);
			virtual ~MateriaSource();

			//Imeatria interface impl
			void learnMateria(AMateria* m);
			AMateria* createMateria(std::string const & type);
	private:
			AMateria* _templates[4]; //stores learned materia temp
			void _clearTempl();
};

#endif
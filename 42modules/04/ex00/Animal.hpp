/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 17:25:18 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/05 17:42:08 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal{
	public:
			Animal();
			Animal(const Animal &copy);
			Animal &operator=(const Animal &assign);
			~Animal();

			void makeSound();
	
	protected:
		std::string type;
};

#endif
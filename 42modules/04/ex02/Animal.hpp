/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 17:25:18 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/11 15:00:00 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
abstract base class - cannot be instantiated directly
derived classes must implemet the pure virtual func
access polymorphically via base class pointers -> heap dynamic allocation*/
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal{
	public:
			Animal();
			Animal(const Animal &copy);
			Animal &operator=(const Animal &assign);
			virtual ~Animal();

			virtual void makeSound() const = 0; //pure virtual
			std::string getType() const;
	
	protected:
		std::string _type;
};

#endif
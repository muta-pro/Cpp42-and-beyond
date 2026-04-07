/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 17:25:18 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/07 19:17:38 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
class accessed polymorphically : via baseclass pointers -> heap dynamic alloc
here we introduce polymorphic destruction*/
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

			virtual void makeSound();
	
	protected:
		std::string _type;
};

#endif
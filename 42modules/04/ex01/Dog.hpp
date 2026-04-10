/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 17:27:03 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/10 18:17:48 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	public:
			Dog();
			Dog(const Dog &copy);
			Dog &operator=(const Dog &assign);
			~Dog();

			void makeSound() const;
			void setIdea(int indx, const std::string &idea);
			std::string getIdea(int indx) const;
			
	private:
			Brain* _brain;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:52:32 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/11 14:15:44 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
we allocate array of pointers, not objs: because it's a standard for storing
mixed types of derived classes in a single array//
because ~Animal is virtual, brains don't leak - deleting animal pointer,
it triggers subclass destructors and ~Brain one as well//
curly braces create local scope,
after program leaves it, local vars are destroyed, no double free bc two obj
don't share the same memory address//
*/
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

#define ARR_SIZE 10

int main()
{
	std::cout << "POLYMORPHIC DESTRUCRION" << std::endl;

	Animal* animals[ARR_SIZE];

	for (int i = 0; i < ARR_SIZE; i++) {
		if (i < ARR_SIZE / 2) {
			std::cout << "Creating Dog " << i << std::endl;
			animals[i] = new Dog();
		}
		else {
			std::cout << "Creating Cat" << i << std::endl;
			animals[i] = new Cat();
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < ARR_SIZE; i++) {
		std::cout << "Delete Animal " << i << std::endl;
			delete animals[i];
			std::cout << std::endl;
	}
	std::cout << "Array destroyed calling properly destructors" << std::endl;

	std::cout << "\nDEEP COPY TEST\n" << std::endl; //two objs have different brains
	{
		std::cout << "Inside local scope, creating Dog and his copy" << std::endl;
		
		Dog Lessy;
		Lessy.setIdea(0, "I want to go home");
		std::cout << "Lessy's idea: " << std::endl;
		Lessy.getIdea(0);

		Dog Max =  Lessy; //copy constructor
		std::cout << "Max's idea: " << std::endl;
		Max.getIdea(0);
		Max.setIdea(0, "I wanna steak");

		std::cout << "Lessy's idea: " << std::endl;
		Lessy.getIdea(0);
		std::cout << "Max's idea: " << std::endl;
		Max.getIdea(0);
		std::cout << "\n they have different brains\n" << std::endl;

		std::cout << "Leaving local scope, destroying both objs\n" << std::endl;
	}
	std::cout << "\nASSIGNMENT" << std::endl;
	{
		Cat Gina;
		Gina.setIdea(0, "Stupid humans");
		std::cout << "\nGina's idea: " << std::endl;
		Gina.getIdea(0);

		Cat Tom;
		Tom.setIdea(0, "I'll cook Jerry");
		std::cout << "\nTom's idea: " << std::endl;
		Tom.getIdea(0);

		Tom = Gina; //assignemnt operator called
		std::cout << "\nTom's idea after talking to Gina: " << std::endl;
		Tom.getIdea(0);
	}

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

	return (0);
}

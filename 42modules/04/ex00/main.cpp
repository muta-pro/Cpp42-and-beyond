/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 17:23:03 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/09 18:46:37 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
putting () after new Dog -> makes value init, setting ints to 0, bools to false)*/
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\nDYNAMIC BINDING" << std::endl;
	const Animal* animal = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat(); //upcasting

	std::cout << "\nGET TYPE" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	j->makeSound(); //Subtype Polymorphism
	i->makeSound();
	animal->makeSound();

	delete animal;
	delete i;
	delete j;

	std::cout << "\nSTATIC BINDING" << std::endl;

	const WrongAnimal* x = new WrongCat();
	const WrongAnimal* y = new WrongAnimal();

	std::cout << "\nGET TYPE" << std::endl;
	std::cout << x->getType() << " " << std::endl;
	std::cout << y->getType() << " " << std::endl;

	x->makeSound();
	y->makeSound();

	delete x;
	delete y;
	
	return (0);
}
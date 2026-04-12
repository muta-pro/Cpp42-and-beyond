/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:52:32 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/11 15:01:17 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	//cannot compile because it's an abstract class
	// Animal generic;
	// Animal* p = new Animal();
	// Animal arr[3];

	Animal* animals[4];
	animals[0] = new Dog();
	animals[1] = new Dog();
	animals[2] = new Cat();
	animals[3] = new Cat();

	for (int i = 0; i < 4; i++) {
		delete animals[i];
	}

	std::cout << "\npolymorphism works" << std::endl;

	return (0);
}

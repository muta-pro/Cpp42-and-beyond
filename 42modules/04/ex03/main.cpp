/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 15:25:35 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/11 16:25:08 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"

int main()
{
    
    std::cout << "Cannot create AMateria directly (abstract)\n" << std::endl;
    
    Ice* ice = new Ice();
    Cure* cure = new Cure();
    
    std::cout << "\nIce type: " << ice->getType() << std::endl;
    std::cout << "Cure type: " << cure->getType() << std::endl;
    
    std::cout << "Cloning ice materia:\n" << std::endl;
    AMateria* ice_clone = ice->clone();
    std::cout << "Clone type: " << ice_clone->getType() << std::endl;
    
    std::cout << "\nCloning cure materia:\n" << std::endl;
    AMateria* cure_clone = cure->clone();
    std::cout << "Clone type: " << cure_clone->getType() << std::endl;
    
    std::cout << "\n Clones are independent objects with same type!" << std::endl;
    
    AMateria* materias[4];
    materias[0] = new Ice();
    materias[1] = new Cure();
    materias[2] = ice->clone();   // Clone through base pointer!
    materias[3] = cure->clone();  // Clone through base pointer!
    
    std::cout << "\nMaterias in array:" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << i << ": " << materias[i]->getType() << std::endl;
    }
    
    std::cout << "\n✓ Polymorphic cloning works!" << std::endl;

    
    Character bob("Bob");
    Character alice("Alice");
    
    std::cout << "\nUsing materias on characters:\n" << std::endl;
    ice->use(bob);
    cure->use(alice);
    
    std::cout << "\nPolymorphic use:\n" << std::endl;
    materias[0]->use(bob);   // Ice
    materias[1]->use(alice); // Cure
    
    std::cout << "\n✓ Polymorphic behavior through ICharacter interface!" << std::endl;
    
    Ice ice1;
    Ice ice2;
    
    std::cout << "\nBefore assignment:" << std::endl;
    std::cout << "ice1 type: " << ice1.getType() << std::endl;
    std::cout << "ice2 type: " << ice2.getType() << std::endl;
    
    std::cout << "\nPerforming assignment:\n" << std::endl;
    ice2 = ice1;
    
    std::cout << "\nAfter assignment:" << std::endl;
    std::cout << "ice1 type: " << ice1.getType() << std::endl;
    std::cout << "ice2 type: " << ice2.getType() << std::endl;
    
    std::cout << "\n✓ Type remains 'ice' (identity preserved)!" << std::endl;
    
    delete ice;
    delete cure;
    delete ice_clone;
    delete cure_clone;
    
    for (int i = 0; i < 4; i++) {
        delete materias[i];
    }
    
    return 0;
}
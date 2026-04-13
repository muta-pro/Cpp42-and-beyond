/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 15:25:35 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/12 20:30:02 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
    
    std::cout << "Cannot create AMateria directly (abstract class)\n" << std::endl;
    std::cout << "Concrete class imp. & pure virtuals(override clone())\n" << std::endl;
    
    Ice* ice = new Ice();
    Cure* cure = new Cure();
    std::cout << "\nIce type: " << ice->getType() << std::endl;
    std::cout << "Cure type: " << cure->getType() << std::endl;

    std::cout << "\n~~Prototype pattern (clone() not knowing type)\n" << std::endl;  
    std::cout << "Cloning ice materia:\n" << std::endl;
    AMateria* ice_clone = ice->clone();
    std::cout << "Clone type: " << ice_clone->getType() << " at " << ice_clone << std::endl;
    std::cout << "Original type: " << ice->getType() << " at " << ice << std::endl;

    std::cout << "\nCloning cure materia:\n" << std::endl;
    AMateria* cure_clone = cure->clone();
    std::cout << "Clone type: " << cure_clone->getType() << std::endl;
    std::cout << "\n ->>Clones are independent objects with same type!" << std::endl;
    
    std::cout << "\n~~Polymorphism: base-class pointers\n" << std::endl;
    //treat different types uniformly
    AMateria* materias[4];
    materias[0] = new Ice();
    materias[1] = new Cure();
    materias[2] = ice->clone(); // Clone through base pointernot knowing type
    materias[3] = cure->clone();
    
    std::cout << "\nMaterias*** in array:" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << i << ": " << materias[i]->getType() << std::endl;
    }

    std::cout << "\n~~Interfaces and Polymorphic behavior -Icharcater" << std::endl;
    Character bob("Bob");
    Character alice("Alice");
    std::cout << "\nUsing materias on characters:" << std::endl;
    ice->use(bob); //ice know bob through interface
    cure->use(alice);
    std::cout << "\nPolymorphic use through base-pointers:" << std::endl;
    materias[0]->use(bob);   // Ice::use()
    materias[1]->use(alice); // Cure::use()

    std::cout << "\n~~Assignment and _type(identity)" << std::endl;
    Ice ice1;
    Ice ice2;
    std::cout << "\nBefore assignment:" << std::endl;
    std::cout << "ice1 type: " << ice1.getType() << std::endl;
    std::cout << "ice2 type: " << ice2.getType() << std::endl;
    ice2 = ice1;
    std::cout << "\nAfter assignment:" << std::endl;
    std::cout << "ice1 type: " << ice1.getType() << std::endl;
    std::cout << "ice2 type: " << ice2.getType() << std::endl;
    std::cout << "\nType remains 'ice' (identity preserved)!" << std::endl;

    std::cout << "\n~~Factory pattern (MateriaSource)" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    std::cout << "\n~~creating materia objs from templates by string\n" << std::endl;
    AMateria* create_ice = src->createMateria("ice");
    AMateria* create_blood = src->createMateria("blood"); //returns NULL
    std::cout << "Created ice: " << create_ice->getType() << std::endl;
    std::cout << "Created blood: " << (create_blood ? "ERROR" : "NULL") << std::endl;

    std::cout << "~~Inventory menagement - Character" << std::endl;
    ICharacter* me = new Character("Ivan");
    std::cout << "filling inventory" << std::endl;
    me->equip(create_ice);
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));
    me->equip(src->createMateria("cure"));
    //invenoty full
    AMateria* extra = src->createMateria("ice");
    me->equip(extra);
    delete extra;

    std::cout << "\n~~Usage materias from inventory- slot validiy" << std::endl;
    ICharacter* target = new Character("Bob");
    me->use(0, *target); //ice
    me->use(1, *target); //cure
    me->use(9, *target);

    std::cout << "~~Removing Materias" << std::endl;
    AMateria* temp = src->createMateria("ice");
    ICharacter* batman = new Character("Batman");
    batman->equip(temp);
    batman->use(0, *target);

    AMateria* ground[4] = {NULL, NULL, NULL, NULL}; //ground storage
    int groundCount = 0;

    batman->unequip(0); //remove from inventory
    ground[groundCount++] = temp; //MUST save the address

    batman->use(0, *target); //empty slot
    for (int i = 0; i < 4; i++) {
        delete ground[i];
    }
    //unequip pervents use-after-free bugs
    std::cout << "~~DEEP COPY Character\n" << std::endl;
    //copy constructor calls clone on each materia
    Character origin("Origin");
    origin.equip(src->createMateria("ice"));
    origin.equip(src->createMateria("cure"));
    Character originCopy = origin;
    origin.use(0, *target);
    origin.use(1, *target);
    originCopy.use(0, *target);
    originCopy.use(1, *target);
    //assignment
    Character originCopy2("copy2");
    originCopy2.use(0, *target);
    originCopy2 = origin; //delets old inventory, clones new
    originCopy2.use(0, *target);
    originCopy2.use(1, *target);

    delete ice;
    delete cure;
    delete ice_clone;
    delete cure_clone;
    
    for (int i = 0; i < 4; i++) {
        delete materias[i];
    }

    delete target;
    delete me;
    delete batman;
    delete src;
    
    return (0);
}

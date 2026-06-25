/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 06:38:53 by imutavdz          #+#    #+#             */
/*   Updated: 2026/06/25 08:51:00 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{ 

	Data d = {1, "test", 3.3};
	Data *p =  &d;

	uintptr_t serializedRaw = Serializer::serialize(p);
	std::cout << "Original data-ptr address: \n" << serializedRaw << "\n";

	Data *deserializedPtr = Serializer::deserialize(serializedRaw);
	std::cout << "Deserialized ptr address: \n" << deserializedPtr << "\n";

	if (p == deserializedPtr)
		std::cout << "pointers match\n";
	else
		std::cout << "pointers don't match\n";

	serializedRaw += 1000;
	std::cout << "modif value: " << serializedRaw << "\n";
	Data *deserialized = Serializer::deserialize(serializedRaw);
		if (p == deserialized)
			std::cout << "pointers match\n";
		else
			std::cout << "pointers don't match\n";
	return 0;
	
}
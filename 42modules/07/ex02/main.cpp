/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 18:25:48 by imutavdz          #+#    #+#             */
/*   Updated: 2026/07/07 02:13:54 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main()
{
	Array<int> arr(3);
	arr[0] = 1;
	std::cout << "index 0 is: " << arr[0] << std::endl;

	for (unsigned int i = 0; i < arr.size(); i++) {
		arr[i] = i * 2;
		std::cout << "\narray number " << i << "*2 = " << arr[i] << std::endl;
	}

	Array<int> copyNumb(arr);
	arr[0] = 999;
	std::cout << "\nnumber at indx 0 is now " << arr[0] << std::endl;
	std::cout << "\ncopy arr indx 0 is still " << copyNumb[0] << std::endl;

	Array<int> assignedArr;
	assignedArr = arr;
	arr[0] = 666;
	std::cout << "assignedArr indx 0 is " << assignedArr[0] << std::endl;
	std::cout << "arr indx 0 is " << arr[0] << std::endl;

	try {
		std::cout << arr[4] << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "\nCaught exception: " << e.what() << std::endl;
	}

	const Array<int> ConstArr(arr);
	std::cout << "const array index 0 is " << ConstArr[0] << std::endl;
	// ConstArr[0] = 5;

	Array<std::string> emptyArr;
	std::cout << "\ndefault construtor called:\nArray size: " << emptyArr.size() << std::endl;
	Array<std::string> words(2);
	words[0] = "hello";
	words[1] = "world";
	for (unsigned int i = 0; i < words.size(); i++) {
		std::cout << words[i] << ' ';
		std::cout << std::endl;
	}

	return 0;
}
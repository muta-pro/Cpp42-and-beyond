/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 08:26:59 by imutavdz          #+#    #+#             */
/*   Updated: 2026/03/12 14:23:10 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>


// int main ()
// {
// 	std::string s = "HI THIS IS BRAIN";
// 	std::string* stringPTR = &s;
// 	std::string& stringREF = s;
// 	std::cout << "address of string var: " << &s << std::endl;
// 	std::cout << "address held by stringPTR: " << stringPTR << std::endl;
// 	std::cout << "address held by stringREF: " << &stringREF << std::endl;
// 	std::cout << "value string var: " << s << std::endl;
// 	std::cout << "value pointed to by stringPTR: " << *stringPTR << std::endl;
// 	std::cout << "value pointed to by stringREF: " << s << std::endl;

// 	return 0;
// }


//11++ verison introduces brace init to unify diffrent kinds

int main()
{
	std::string brain{"HI THIS IS BRAIN"};

	std::string* ptr{&brain};
	std::string& ref{brain};
	std::cout << "address of brain: " << &brain << '\n';
	std::cout << "address held by ptr: " << ptr << '\n';
	std::cout << "address of ref: " << &ref << '\n';
	std::cout << "value if brain: " << brain << '\n';
	std::cout << "value pointed by ptr: " << *ptr << '\n';
	std::cout << "value through ref: " << ref << '\n';
	return 0;
}

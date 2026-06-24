/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:13:34 by imutavdz          #+#    #+#             */
/*   Updated: 2026/06/24 13:36:17 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static  e_type detecType(std::string &s) {

}

static void printFromFloat(float n) {
	std::cout << "float: " << n;
}
static void printFromInt(int n) {
	char c = static_cast<char>(n);
	float f = static_cast<char>(n);
	double d = static_cast<char>(n);

	std::cout << "char :";
	if (n < 0 || n > 127) {
		std::cout << "impossible\n";
	} else if (!std::isprint(c)) {
		std::cout << "Non displayable\n";
	} else {
		std::cout << "'" << c << "'\n";
	}
	std::cout << "int: " << n << "\n";
	std::cout << "float: " << f << "\n";
	std::cout << "double: " << d << "\n";
}

static void printFromDouble(double n) {
	std::cout << "double: " << n;
}
static void printChar(char c) {
	std::cout << "char: " << c;
}

void ScalarConverter::convert(const std::string &s) {
	int t = detectType(s);
	switch(t) {
	case INT_T:
		try 
		{
			int val = std::stoi(s);
			printFromInt(val);
		} catch (const std::exception &e) {
			std::cout << "char:impossible\nint:impossible\nfloat:impossible\ndouble:impossible\n";
		}
		break ;
	case FLOAT_T:
		try
		{
			float val = std::stof(s);
			printFromFloat(val);
		} catch (const std::exception &e) {
			std::cout << "char:impossible\nint:impossible\nfloat:impossible\ndouble:impossible\n";
		}
		break ;
	case DOUBLE_T:
		try
		{
			double val = std::stod(s);
			printFromDouble(val);
		} catch {
			std::cout << "char:impossible\nint:impossible\nfloat:impossible\ndouble:impossible\n";
		}
	case CHAR_T:
		{
			char val = s[0];
			printFromChar(val);
		}
		break ;
	case PSEUDO_T:
		try
		{

		}
		}
		catch (const std::invalid_argument &e) {
			std::cout << "Err: not a valid number." << std::endl;
		}
		catch (const std::out_of_range & e) {
			std::cout << "impossible" << std::endl;
		}
	}
	outputCast(val);
}
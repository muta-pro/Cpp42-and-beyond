/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:13:34 by imutavdz          #+#    #+#             */
/*   Updated: 2026/06/25 06:37:12 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

namespace {
	enum e_type {CHAR_T, INT_T, FLOAT_T, DOUBLE_T, UNKNOWN_T};

	e_type 	detectType(const std::string &s) {
		if (s == "nan" || s == "+inf" || s == "-inf")
			return DOUBLE_T;
		if (s == "nanf" || s == "-inff" || s == "+inff")
			return FLOAT_T;
		if (s.length() == 1 && !std::isdigit(s[0]))
			return CHAR_T;
		bool hasD = false;
		bool hasF = false;
		bool hasDigit = false;

		size_t i = 0;
		if (s[i] == '+' || s[i] == '-') {
			i++;
		}
		if (i == s.length())
			return UNKNOWN_T;
		for (; i < s.length(); i++) {
			if (std::isdigit(s[i]))
				hasDigit = true;
			else if (s[i] == '.') {
				if (hasD)
					return UNKNOWN_T;
				hasD = true;
			}
			else if (s[i] == 'f') {
				if (hasF || i != s.length() - 1 || !hasD || !hasDigit) {
					return UNKNOWN_T;
				}
				hasF = true;
			}
			else
				return UNKNOWN_T;
		}
		if (!hasDigit)
			return UNKNOWN_T;
		if (hasF)
			return FLOAT_T;
		if (hasD)
			return DOUBLE_T;
		return INT_T;
	}
	void	printFromFloat(float n) {

		std::cout << "char: ";
		if (std::isnan(n) || n < 0 || n > 127) {
			std::cout << "impossible\n";
		} else {
			char	c = static_cast<char>(n);
			if (!std::isprint(c))
				std::cout << "Non displayable\n";
			else
				std::cout << "'" << c << "'\n";
		}
		if (n >= static_cast<float>(std::numeric_limits<int>::max())
			 || n <= static_cast<float>(std::numeric_limits<int>::min()) || n != n)
			std::cout << "int: impossible\n";
		else {
			int		a = static_cast<int>(n);
			std::cout << "int: " << a << "\n";
		}
		double	d = static_cast<double>(n);
		if (std::isnan(n) || std::isinf(n)) {
			std::cout << "double: " << d << "\n";
			std::cout << "float: " << n << "f\n";
		}
		else if (!std::isnan(n) && !std::isinf(n) && n == static_cast<int>(n)) {
			std::cout << "double: " << d << ".0\n";
			std::cout << "float: " << n << ".0f\n";
		}
		else {
			std::cout << "double: " << d << "\n";
			std::cout << "float: " << n << "f\n";
		}
	}
	void printFromInt(int n) {
		char	c = static_cast<char>(n);
		float	f = static_cast<float>(n);
		double	d = static_cast<double>(n);
		
		std::cout << "char: ";
		if (n < 0 || n > 127) {
			std::cout << "impossible\n";
		} else if (!std::isprint(c)) {
			std::cout << "Non displayable\n";
		} else
			std::cout << "'" << c << "'\n";
		std::cout << "int: " << n << "\n";
		std::cout << "float: " << f << ".0f\n";
		std::cout << "double: " << d << ".0\n";
	}
	
	void printFromDouble(double n) {
		std::cout << "char: ";
		if (std::isnan(n) || n < 0 || n > 127) {
			std::cout << "impossible\n";
		} else {
			char	c = static_cast<char>(n);
			if (!std::isprint(c)) {
				std::cout << "Non displayable\n";
			} else {
				std::cout << "'" << c << "'\n";
			}
		}
		if (n > std::numeric_limits<int>::max() || n < std::numeric_limits<int>::min()
				|| n != n)
			std::cout << "int: impossible\n";
		else {
			int		a = static_cast<int>(n);
			std::cout << "int: " << a << "\n";
		}
		if (n != n)
			std::cout << "float: nanf\n";
		else if (n > std::numeric_limits<float>::max())
			std::cout << "float: inff\n";
		else if (n < -std::numeric_limits<float>::max())
			std::cout << "float: -inff\n";
		else {
			float	f = static_cast<float>(n);
			if (f < static_cast<float>(std::numeric_limits<int>::max())
				&& f > static_cast<float>(std::numeric_limits<int>::min())
					&& f == static_cast<int>(f))
				std::cout << "float: " << f << ".0f\n";
			else
				std::cout << "float: " << f << "f\n";
		}
		if (!std::isnan(n) && !std::isinf(n)
				&& n == static_cast<int>(n) && n < 1000000 && n > -1000000)
			std::cout << "double: " << n << ".0\n";
		else
			std::cout << "double: " << n << "\n";
	}
	
	void printFromChar(char c) {
		double	d = static_cast<double>(c);
		int		a = static_cast<int>(c);
		float	f = static_cast<float>(c);

		std::cout << "char: '" << c << "'\n";
		std::cout << "int: " << a << "\n";
		std::cout << "float: " << f << ".0f\n";
		std::cout << "double: " << d << ".0\n";
	}
}

void ScalarConverter::convert(const std::string &s) {
	e_type t = detectType(s);
	switch(t) {
	case INT_T:
		try 
		{
			int val = std::stoi(s);
			printFromInt(val);
		} catch (const std::exception &e) {
			std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
		}
		break ;
	case FLOAT_T:
		try
		{
			float val = std::stof(s);
			printFromFloat(val);
		} catch (const std::exception &e) {
			std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
		}
		break ;
	case DOUBLE_T:
		try
		{
			double val = std::stod(s);
			printFromDouble(val);
		} catch (const std::exception &e) {
			std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
		}
		break ;
	case CHAR_T:
		{
			printFromChar(s[0]);
			break ;
		}
		break ;
	case UNKNOWN_T:
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
		break ;
	}
}
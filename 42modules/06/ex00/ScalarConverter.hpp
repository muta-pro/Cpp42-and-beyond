/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:13:37 by imutavdz          #+#    #+#             */
/*   Updated: 2026/06/25 05:26:05 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include <limits>
#include <cmath>
#include <cctype>

class ScalarConverter {
	public:
			ScalarConverter () = delete;
			ScalarConverter (const ScalarConverter  &copy) = delete;
			ScalarConverter  &operator=(const ScalarConverter  &assign) = delete;
			~ScalarConverter () = delete;

			static void convert(const std::string &s);
};

#endif
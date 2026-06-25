/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 06:39:46 by imutavdz          #+#    #+#             */
/*   Updated: 2026/06/25 07:11:50 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>
#include "Data.hpp"

class Serializer
{
public:
	Serializer() = delete;
	Serializer(const Serializer &copy) = delete;
	Serializer &operator=(const Serializer &assign) = delete;
	~Serializer() = delete;

	static uintptr_t	serialize(Data *ptr);
	static Data			*deserialize(uintptr_t raw);
	
};

#endif
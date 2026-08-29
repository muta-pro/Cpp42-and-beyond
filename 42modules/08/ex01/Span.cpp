/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 19:09:37 by imutavdz          #+#    #+#             */
/*   Updated: 2026/08/29 14:59:42 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span(std::size_t capacity) : _capacity(capacity) {
	_num.reserve(capacity);
}

void addNumber(int value) {
	if (_num.size() >= _capacity)
		throw std::overflow_error("Span is full");
	_num.push_back(value);
}


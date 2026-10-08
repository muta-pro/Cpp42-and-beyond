/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 19:09:37 by imutavdz          #+#    #+#             */
/*   Updated: 2026/10/08 22:47:32 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() :_capacity(0) {} //init objs limit

Span::Span(unsigned int maxSize) : _capacity(maxSize) {
	_collection.reserve(_capacity);
}

void Span::AddNumber(int value) {
	if (_collection.size() >= _capacity) //enforcing the limit-rule
		throw std::overflow_error("Span is full");
	_collection.push_back(value);
}

long long Span::shortestSpan() const {
	if (_collection.size() <= 1)
		throw std::logic_error("Not enough values");
	std::vector<int> sorted = _collection;
	std::sort(sorted.begin(), sorted.end());

	std::vector<int> differences(sorted.size());
	std::adjacent_difference(sorted.begin(), sorted.end(), differences.begin());
	auto smallest = std::min_element(differences.begin() + 1, differences.end());
	return *smallest;
}

long long Span::longestSpan() const {
	if (_collection.size() <= 1)
		throw std::logic_error("Not enough values");
	auto minmax = std::minmax_element(_collection.begin(), _collection.end());
	return static_cast<long long>*minmax.second - static_cast<long long>*minmax.first;
}

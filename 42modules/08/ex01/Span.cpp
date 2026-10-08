/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 19:09:37 by imutavdz          #+#    #+#             */
/*   Updated: 2026/10/09 00:05:46 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <numeric>

Span::Span() : _capacity(0) {}

Span::Span(unsigned int maxSize) : _capacity(maxSize) {
	// Reserve storage without adding any numbers.
	_collection.reserve(_capacity);
}

void Span::AddNumber(int value) {
	if (_collection.size() >= _capacity)
		throw std::overflow_error("Span is full");
	_collection.push_back(value);
}

long long Span::shortestSpan() const {
	if (_collection.size() <= 1)
		throw std::logic_error("Not enough values");
	// Convert the inputs before subtracting, and keep the original order intact.
	std::vector<long long> sorted(_collection.begin(), _collection.end());
	std::sort(sorted.begin(), sorted.end());

	std::vector<long long> differences(sorted.size());
	std::adjacent_difference(sorted.begin(), sorted.end(), differences.begin());
	// The first output is the first value itself, so only inspect later outputs.
	auto smallest = std::min_element(differences.begin() + 1, differences.end());
	return *smallest;
}

long long Span::longestSpan() const {
	if (_collection.size() <= 1)
		throw std::logic_error("Not enough values");
	auto minmax = std::minmax_element(_collection.begin(), _collection.end());
	return static_cast<long long>(*minmax.second) - static_cast<long long>(*minmax.first);
}

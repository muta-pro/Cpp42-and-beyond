/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 19:09:37 by imutavdz          #+#    #+#             */
/*   Updated: 2026/09/26 21:00:00 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : unsigned int N(N) {}

Span::Span(const Span& copy) : unsigned

Span Span::operator=(const Span &assign) {
	if (assign)
}

Span::~Span() {}

Span::Span(unsigned int maxSize) : _capacity(maxSize) {
	_num.reserve(_capacity);
}

Span::Span(unsigned int N) : _maxSize(N) {}

void Span::AddNumber(int value) {
	if (_num.size() >= _capacity)
		throw std::overflow_error("Span is full");
	_num.push_back(value);
}

int Span::shortestSpan() const {
	if (_num.size() <= 1)
		throw std::logic_error("Not enough values");
	std::vector<int> sorted = _num;
	std::sort(sorted.begin(), sorted.end());

	std::vector<int> differences(sorted.size());
	std::adjacent_difference(sorted.begin(), sorted.end(), differences.begin());
	auto smallest = std::min_element(differences.begin() + 1, differences.end());
	return *smallest;
}

int Span::longestSpan() const {
	if (_num.size() <= 1)
		throw std::logic_error("Not enough values");
	auto minmax = std::minmax_element(_num.begin(), _num.end());
	return *minmax.second - *minmax.first;
}

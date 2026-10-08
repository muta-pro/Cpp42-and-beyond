/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 19:09:42 by imutavdz          #+#    #+#             */
/*   Updated: 2026/10/08 18:39:54 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <numeric>
#include <vector>
#include <stdexcept>
#include <concepts>
#include <iterator>
#include <cstddef>

class Span {
public:
	Span();
	Span(unsigned int N);
	Span(const Span& copy);
	Span &operator=(const Span& assign);
	~Span();

	void	AddNumber(int n);
	int		shortestSpan() const;
	int		longestSpan() const;

	template <std::forward_iterator Iter>
	requires std::convertible_to<std::iter_value_t<Iter>, int>
	void AddRange(Iter first, Iter last) {
		const auto amountToAdd = std::distance(first, last);
		if (amountToAdd < 0) 
			throw std::overflow_error("Invalid iterator range");
		std::size_t spaceLeft = _capacity - _collection.size();
		if (static_cast<std::size_t>(amountToAdd) > spaceLeft)
			throw std::overflow_error("Range does not fit");
		_collection.insert(_collection.end(), first, last);
	}
private:
	std::vector<int>	_collection;
	unsigned int		_capacity;
};

#endif

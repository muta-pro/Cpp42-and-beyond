/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 19:09:42 by imutavdz          #+#    #+#             */
/*   Updated: 2026/10/09 00:16:28 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <concepts>
#include <cstddef>
#include <iterator>
#include <stdexcept>
#include <vector>

class Span {
public:
	Span();
	explicit Span(unsigned int maxSize);
	Span(const Span& copy) = default;
	Span &operator=(const Span& assign) = default;
	~Span() = default;

	void			AddNumber(int n);
	long long		shortestSpan() const;
	long long		longestSpan() const;

	template <std::forward_iterator Iter>
	requires std::same_as<std::iter_value_t<Iter>, int>
	void AddRange(Iter first, Iter last) {
		// first and last must describe a valid range in the same container.
		// Forward iterators let us count the range, then walk it again to copy.
		const auto amountToAdd = std::distance(first, last);
		if (amountToAdd < 0)
			throw std::invalid_argument("Range is reversed");
		const std::size_t spaceLeft = _capacity - _collection.size();
		if (static_cast<std::size_t>(amountToAdd) > spaceLeft)
			throw std::overflow_error("Range does not fit");
		_collection.insert(_collection.end(), first, last);
	}
private:
	std::vector<int>	_collection;
	unsigned int		_capacity;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 19:09:42 by imutavdz          #+#    #+#             */
/*   Updated: 2026/08/29 15:15:13 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <vector>
#include <stdexcept>
#include <concepts>
#include <ranges>
#include <iterator>

class Span {
public:
	Span();
	Span(unsigned int N);
	Span(const Span& copy);
	Span &operator=(const Span& assign);
	~Span();

	void	AddNumber(int n);
	int		shortestS() const;
	int		longestS() const;

	template <std::forward_iterator Iter>
	requires std::coneritble_to<std::iter_reference_t<Iterator>, int>
	void AddNumber(Iter first, Iter last) {
		const auto count = std::ranges::distance(first, last);
		const auto remaining = _capacity - _num.size();

		if (count < 0 || count > static_cast<std::iter_difference_t<Iterator>>(remaining)) {
			throw std::overflow_error("No space in Span");
		}
		_num.insert(_num.end(), first, last);
	}

private:
	std::vector<int>	_num;
	std::size_t			_capacity;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 19:09:42 by imutavdz          #+#    #+#             */
/*   Updated: 2026/08/22 19:25:35 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <vector>
#include <stdexcept>

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

	template <typename It>
	void AddNumbers(It begin, It end) {
		if (std::distance(begin, end) > _max_size - _num.size()) {
			throw std::overflow_error("not enough space to add numbers");
		}
		_num.insert(_num.end(), _num.begin(), end);
	}

private:
	unsigned int		_max_size;
	std::vector<int>	_num;
};

#endif
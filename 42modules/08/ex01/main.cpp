/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 19:08:56 by imutavdz          #+#    #+#             */
/*   Updated: 2026/10/09 00:08:37 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <limits>
#include <list>
#include <numeric>
#include <set>
#include <stdexcept>
#include <vector>

// Check actual answers instead of only printing numbers that look plausible.
void checkSpans(const char* label, const Span& span,
		long long expectedShortest, long long expectedLongest) {
	const long long shortest = span.shortestSpan();
	const long long longest = span.longestSpan();
	if (shortest != expectedShortest || longest != expectedLongest)
		throw std::runtime_error("A span calculation gave the wrong answer");
	std::cout << label << ": shortest = " << shortest
		<< ", longest = " << longest << '\n';
}

// Both calculations must reject a collection with fewer than two numbers.
void checkTooFewValues(const Span& span) {
	try {
		span.shortestSpan();
		throw std::runtime_error("shortestSpan should have thrown an exception");
	}
	catch (const std::logic_error& e) {
		std::cout << "Expected shortestSpan error: " << e.what() << '\n';
	}
	try {
		span.longestSpan();
		throw std::runtime_error("longestSpan should have thrown an exception");
	}
	catch (const std::logic_error& e) {
		std::cout << "Expected longestSpan error: " << e.what() << '\n';
	}
}

int main() {
	try {
		// Single-number insertion: the example with known answers.
		Span example(5);
		example.AddNumber(6);
		example.AddNumber(3);
		example.AddNumber(17);
		example.AddNumber(9);
		example.AddNumber(11);
		checkSpans("Five numbers", example, 2, 14);

		// Range insertion works with different kinds of int containers.
		Span mixed(8);
		const std::vector<int> vec = {1, 2, 3};
		const std::list<int> lst = {33, 44, 55};
		const std::set<int> st = {4, 5};
		mixed.AddRange(vec.begin(), vec.end());
		mixed.AddRange(lst.begin(), lst.end());
		mixed.AddRange(st.begin(), st.end());
		checkSpans("Vector, list and set", mixed, 1, 54);

		// An empty range adds nothing, even when the Span is already full.
		const std::vector<int> emptyRange;
		mixed.AddRange(emptyRange.begin(), emptyRange.end());
		checkSpans("After an empty range", mixed, 1, 54);

		Span duplicates(2);
		duplicates.AddNumber(5);
		duplicates.AddNumber(5);
		checkSpans("Duplicates", duplicates, 0, 0);

		Span negatives(3);
		const std::vector<int> negativeValues = {-10, -3, 2};
		negatives.AddRange(negativeValues.begin(), negativeValues.end());
		checkSpans("Negative numbers", negatives, 5, 12);

		// Convert before subtracting, including when calculating the expectation.
		const int lowest = std::numeric_limits<int>::min();
		const int highest = std::numeric_limits<int>::max();
		const long long fullGap = static_cast<long long>(highest)
			- static_cast<long long>(lowest);
		Span extremes(2);
		extremes.AddNumber(lowest);
		extremes.AddNumber(highest);
		checkSpans("Smallest and largest int", extremes, fullGap, fullGap);

		Span emptySpan;
		checkTooFewValues(emptySpan);
		try {
			emptySpan.AddNumber(1);
			throw std::runtime_error("A zero-capacity Span accepted a number");
		}
		catch (const std::overflow_error& e) {
			std::cout << "Expected zero-capacity error: " << e.what() << '\n';
		}

		Span single(1);
		single.AddNumber(7);
		checkTooFewValues(single);
		try {
			single.AddNumber(8);
			throw std::runtime_error("A full Span accepted another number");
		}
		catch (const std::overflow_error& e) {
			std::cout << "Expected full-Span error: " << e.what() << '\n';
		}

		// A range that will not fit is rejected before any values are inserted.
		Span limited(3);
		limited.AddNumber(10);
		limited.AddNumber(20);
		const std::vector<int> extra = {100, 200};
		try {
			limited.AddRange(extra.begin(), extra.end());
			throw std::runtime_error("An oversized range was accepted");
		}
		catch (const std::overflow_error& e) {
			std::cout << "Expected range error: " << e.what() << '\n';
		}
		limited.AddNumber(30);
		checkSpans("After a rejected range", limited, 10, 20);

		// Copy construction and assignment both copy the values and the limit.
		Span original(3);
		original.AddNumber(10);
		original.AddNumber(20);
		Span copied(original);
		Span assigned;
		assigned = original;
		original.AddNumber(30);
		copied.AddNumber(-10);
		assigned.AddNumber(15);
		checkSpans("Original", original, 10, 20);
		checkSpans("Copy", copied, 10, 30);
		checkSpans("Assigned object", assigned, 5, 10);

		// A predictable large input makes the expected answers easy to verify.
		Span bigSpan(10000);
		std::vector<int> numbers(10000);
		std::iota(numbers.begin(), numbers.end(), 0);
		bigSpan.AddRange(numbers.begin(), numbers.end());
		checkSpans("10,000 numbers", bigSpan, 1, 9999);

		std::cout << "All Span checks passed.\n";
	}
	catch (const std::exception& e) {
		std::cerr << "Unexpected error: " << e.what() << '\n';
		return 1;
	}
	return 0;
}

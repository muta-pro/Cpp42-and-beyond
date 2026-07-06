/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:46:33 by imutavdz          #+#    #+#             */
/*   Updated: 2026/07/06 18:20:06 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <cassert>
#include <iostream>
#include <string>

static int callCount = 0;

template <typename T>
void countCall(const T&) {
	callCount++;
}

template <typename T>
void doubleVal(T& x) {
	x *= 2;
}
//void (*fp)(int&) = &print;
template <typename T>
void print(const T& x) {
	std::cout << x << ' ';
}

template <typename T>
void incr(T& x) {
	x += 1;
}

void iterCallEachElem() {
	callCount = 0;
	int arr[] = {1, 4, 5, 6, 5};
	iter(arr, sizeof(arr) / sizeof(arr[0]), countCall<int>);
	assert(callCount == 5);
	std::cout << "iter calls every element\n";
}

void iterMutatesCheck() {
	int arr[] = {1, 2, 3};
	std::cout << "int arr before: ";
	iter(arr, sizeof(arr) / sizeof(arr[0]), print<int>);
	iter(arr, sizeof(arr) / sizeof(arr[0]), doubleVal<int>);
	assert(arr[0] == 2);
	assert(arr[1] == 4);
	assert(arr[2] == 6);
	std::cout << "int arr double value: ";
	iter(arr, sizeof(arr) / sizeof(arr[0]), print<int>);
	std::cout << "iter mutates correctly\n";

	const int con[] = {10, 20, 30};
	std::cout << "costant array: ";
	iter(con, sizeof(con) / sizeof(con[0]), print<int>);
	// iter(con, sizeof(con) / sizeof(con[0]), incr<int>);
	std::cout << "mutation fails\n";
}

void iterWithStrings() {
	callCount = 0;
	std::string words[] = {"hello", "world"};
	iter(words, sizeof(words) / sizeof(words[0]), countCall<std::string>);
	assert(callCount == 2);
	std::cout << "iter works with strings\n";
}

struct Point {
	int x, y;
};

std::ostream &operator<<(std::ostream &out, const Point &p) {
	return out << "(" << p.x << ", " << p.y << ")\n";
}

int main()
{
	iterCallEachElem();
	iterMutatesCheck();
	iterWithStrings();

	Point points[] = {{1, 2}, {3, 4}, {5, 6}};
	std::cout << "points: \n";
	iter(points, sizeof(points) / sizeof(points[0]), print<Point>);
	//iter(point*arr, sizet len, void(*func)(const Point&))
	//calls print<Point> on each elem

	return 0;
}
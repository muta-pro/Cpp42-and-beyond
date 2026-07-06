/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 18:26:45 by imutavdz          #+#    #+#             */
/*   Updated: 2026/07/06 20:08:54 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//deep copy must be performed, so double freeing is avoided
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array {
	public:
			Array() : _elements(new T[0]()), _size(0) {}
			Array(unsigned int n) : _elements(new T[n]()), _size(n) {}
			Array(const Array &copy) : _elements(new T[copy.size]()), _size(copy._size) {
				for (unsigned int i = 0; i < _size; i++)
				_elements[i] = copy._elements[i];
			}
			Array &operator=(const Array &assign) {
				if (this != assign) {
					delete[] _elements;
					_size = assign._size;
					_elements = new T[_size]();
					for (unsigned int i = 0; i < _size; i++)
						_elements[i] = assign._elements[i];
				}
				return *this;
			}
			~Array() {
				delete[] _elements;
				T& operator[](unsigned int index) {
					if (index >= _size)
						throw OutOfBoundsException();
					return _elements[index];
				const T& operator[](unsigned int index) const {
					if (index >= _size)
						throw OutOfBoundsException();
					return _elements[index];
				}
			}
		}


			unsigned int size() const {
				return _size;
			}

			class OutOfBoundsException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return "Error: indx out of bounds";
				}
			};

	private:
		T*				_elements;
		unsigned int	_size;
};

#endif


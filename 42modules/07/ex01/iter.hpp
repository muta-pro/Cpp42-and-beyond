/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:46:49 by imutavdz          #+#    #+#             */
/*   Updated: 2026/07/06 17:51:52 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <stddef.h>

template <typename T, typename F>
void iter(T *arr, const size_t len, F func)
{
	for(size_t i = 0; i < len; i++) {
		func(arr[i]);
	}
}

#endif
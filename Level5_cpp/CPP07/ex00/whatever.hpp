/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:22:10 by yokitaga          #+#    #+#             */
/*   Updated: 2024/02/11 17:36:14 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b){
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T min(T a, T b){
	if (a < b)
		return a;
	else
		return b;
}

template <typename T>
T max(T a, T b){
	if (a > b)
		return a;
	else
		return b;
}

#endif
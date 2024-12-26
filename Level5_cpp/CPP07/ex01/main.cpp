/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:26:25 by yokitaga          #+#    #+#             */
/*   Updated: 2024/02/11 18:20:06 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void printMessage(const std::string & src)
{
	std::cout << src;
}

int main()
{
	std::string array[] = {"Your ","test " , "will ", "be ", "good ", "if ", "this ", "massage ", "is ", "printed"};
	unsigned int length = sizeof(array) / sizeof(array[0]);
	iter(array, length, printMessage);
	std::cout << std::endl;
	return 0;
}
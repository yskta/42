/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:08:02 by yokitaga          #+#    #+#             */
/*   Updated: 2024/01/07 15:19:58 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

//ex)./sed test.txt a b
int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: invalid arguments" << std::endl;
		return (1);
	}
	sed Sed(argv[1]);
	Sed.replace(argv[2], argv[3]);
	return (0);
}
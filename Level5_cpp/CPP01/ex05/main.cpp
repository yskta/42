/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 17:55:53 by yokitaga          #+#    #+#             */
/*   Updated: 2024/01/20 14:54:13 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	std::string input;
	Harl harl;
	do
	{
		std::cout << "Enter a command {DEBUG/INFO/WARNING/ERROR}: ";
		if (!std::getline(std::cin, input)) {
			std::cout << std::endl;
            std::cerr << "[EOF detected. Exit the program.]" << std::endl;
            std::exit(1);
        }
		harl.complain(input);
	} while (1);
	return (0);
}
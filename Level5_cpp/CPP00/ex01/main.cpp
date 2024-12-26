/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 00:04:03 by yokitaga          #+#    #+#             */
/*   Updated: 2024/01/15 00:25:34 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook phonebook;
	std::string input;

	while (1)
	{
		std::cout << "=============Please enter ADD, SEARCH or EXIT.=============" << std::endl;
		std::cout << "> ";
		if (std::getline(std::cin, input))
		{
			if (input == "ADD")
				phonebook.add();
			else if (input == "SEARCH")
				phonebook.search();
			else if (input == "EXIT")
				phonebook.exit();
			else
				std::cout << "Invalid input. Please retry." << std::endl;
		}
		else{
			std::cerr << "[EOF detected. Exit the program.]" << std::endl;
            std::exit(1);
		}
	}
	return (0);
}
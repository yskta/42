/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:32:39 by yokitaga          #+#    #+#             */
/*   Updated: 2024/01/19 21:30:14 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	currentIndex = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::add(void)
{
	if (currentIndex == MAX_CONTACTS)
		currentIndex = 0;
	contacts[currentIndex].initForAddContact();
	contacts[currentIndex].setIndexForAdd(currentIndex);
	currentIndex++;
}

int PhoneBook::getLastIndex(void)const
{
	int LastIndex = 0;
	while (LastIndex < MAX_CONTACTS)
	{
		if (contacts[LastIndex].getFirstName().empty())
			break ;
		LastIndex++;
	}
	return (LastIndex);
}

void PhoneBook::displayAll(void)const
{
	int i;

	i = 0;
	std::cout << "|==========|==========|==========|==========|" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "|==========|==========|==========|==========|" << std::endl;
	while (i < MAX_CONTACTS)
	{
		if (contacts[i].getFirstName().empty())
			break ;
		contacts[i].displayInstant(i);
		i++;
	}
	std::cout << "|==========|==========|==========|==========|" << std::endl;
}

void PhoneBook::search(void)const
{
	if (getLastIndex() == 0) {
		std::cout << "[No contacts.]" << std::endl;
		return ;
	}
	displayAll();
	while (true) {
        std::cout << "[Please enter the contact index from displayed index number above.]" << std::endl;
        std::cout << "> ";
        std::string userInput;
        if (!std::getline(std::cin, userInput)) {
            std::cerr << "[EOF detected. Exit the program.]" << std::endl;
            std::exit(1);
        }
		char* endPtr;
		long convertInput = std::strtol(userInput.c_str(), &endPtr, 10);
		if (*userInput.c_str() != '\0' && *endPtr == '\0') {
			if (convertInput >= 0 && convertInput < getLastIndex()) {
				contacts[(int)convertInput].displayDetail();
				break;
			} else {
				std::cout << "[Invalid input index number. Please retry.]" << std::endl;
			}
		} else {
			std::cout << "[Invalid input. Please retry.]" << std::endl;
		}
	}
}

void PhoneBook::exit(void)const
{
	std::cout << "[Finished.]" << std::endl;
	std::exit(0);
}


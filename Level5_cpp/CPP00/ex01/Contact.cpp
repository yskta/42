/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:13:54 by yokitaga          #+#    #+#             */
/*   Updated: 2024/01/14 23:33:51 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string	Contact::getFirstName()const
{
	return (first_name);
}

void	Contact::initForAddContact(void)
{
	while (true) {
        std::cout << "[Please enter the first name.]" << std::endl;
        std::cout << "> ";
        if (!std::getline(std::cin, first_name)) {
            std::cerr << "[EOF detected. Exit the program.]" << std::endl;
            std::exit(1);
        }
        if (!first_name.empty()) {
            break;
        }
        std::cout << "[Invalid input. Please retry.]" << std::endl;
    }
	while (true) {
		std::cout << "[Please enter the last name.]" << std::endl;
		std::cout << "> ";
		if (!std::getline(std::cin, last_name)) {
			std::cerr << "[EOF detected. Exit the program.]" << std::endl;
			std::exit(1);
		}
		if (!last_name.empty()) {
			break;
		}
		std::cout << "[Invalid input. Please retry.]" << std::endl;
	}
	while (true) {
		std::cout << "[Please enter the nickname.]" << std::endl;
		std::cout << "> ";
		if (!std::getline(std::cin, nickname)) {
				std::cerr << "[EOF detected. Exit the program.]" << std::endl;
				std::exit(1);
		}
		if (!nickname.empty()) {
			break;
		}
		std::cout << "[Invalid input. Please retry.]" << std::endl;
	}
	while (true) {
		std::cout << "[Please enter the phone number.]" << std::endl;
		std::cout << "> ";
		if (!std::getline(std::cin, phone_number)) {
			std::cerr << "[EOF detected. Exit the program.]" << std::endl;
			std::exit(1);
		}
		if (!phone_number.empty()) {
			break;
		}
		std::cout << "[Invalid input. Please retry.]" << std::endl;
	}
	while (true) {
		std::cout << "[Please enter the darkest secret.]" << std::endl;
		std::cout << "> ";
		if (!std::getline(std::cin, darkest_secret)) {
			std::cerr << "[EOF detected. Exit the program.]" << std::endl;
			std::exit(1);
		}
		if (!darkest_secret.empty()) {
			break;
		}
		std::cout << "[Invalid input. Please retry.]" << std::endl;
	}
}

void   Contact::setIndexForAdd(int index)
{
	this->index = index;
}

void	Contact::displayInstant(int index)const
{
	std::cout << "|";
	std::cout << std::setw(10) << index << "|";
	if (first_name.length() > 10)
		std::cout << first_name.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << first_name << "|";
	if (last_name.length() > 10)
		std::cout << last_name.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << last_name << "|";
	if (nickname.length() > 10)
		std::cout << nickname.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << nickname << "|";
	std::cout << std::endl;
}

void	Contact::displayDetail()const
{
	if (this->first_name.empty())
	{
		std::cout << "No data." << std::endl;
		return ;
	}
	std::cout << "Contact[" << index  << "]" << std::endl;
	std::cout << "1.first name: " << first_name << std::endl;
	std::cout << "2.last name: " << last_name << std::endl;
	std::cout << "3.nickname: " << nickname << std::endl;
	std::cout << "4.phone number: " << phone_number << std::endl;
	std::cout << "5.darkest secret: " << darkest_secret << std::endl;
}




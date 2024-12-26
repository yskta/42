/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:33:12 by yokitaga          #+#    #+#             */
/*   Updated: 2024/01/27 23:37:26 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type_("WrongAnimal") {
	std::cout << "[" << type_ << "] constructor called at WrongAnimal.cpp" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type_(type) {
	std::cout << "[" << type_ << "] constructor called at WrongAnimal.cpp" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
	*this = src;
	std::cout << "[" << type_ << "] copy constructor called at WrongAnimal.cpp" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &right) {
	if (this != &right)
		type_ = right.type_;
	std::cout << "[" << type_ << "] assignation operator called at WrongAnimal.cpp" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "[" << type_ << "] destructor called at WrongAnimal.cpp" << std::endl;
}

std::string WrongAnimal::getType() const {
	return (type_);
}

void WrongAnimal::makeSound() const {
	std::cout << "[" << type_ << "] makeSound called " << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:13:34 by yokitaga          #+#    #+#             */
/*   Updated: 2024/01/28 10:31:16 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type_("Animal") {
	std::cout << "[" << type_ << "] default constructor called at Animal.cpp" << std::endl;
}

Animal::Animal(std::string type) : type_(type) {
	std::cout << "[" << type_ << "] constructor with type called at Animal.cpp" << std::endl;
}

Animal::Animal(const Animal &src) {
	*this = src;
	std::cout << "[" << type_ << "] copy constructor called at Animal.cpp" << std::endl;
}

Animal &Animal::operator=(const Animal &right) {
	if (this != &right)
		type_ = right.type_;
	std::cout << "[" << type_ << "] assignation operator called at Animal.cpp" << std::endl;
	return (*this);
}

Animal::~Animal() {
	std::cout << "[" << type_ << "] destructor called at Animal.cpp" << std::endl;
}

std::string Animal::getType() const {
	std::cout << "[" << type_ << "] getType called at Animal.cpp" << std::endl;
	return (type_);
}

void Animal::makeSound() const {
	std::cout << "[" << type_ << "] makeSound called at Animal.cpp" << std::endl;
}
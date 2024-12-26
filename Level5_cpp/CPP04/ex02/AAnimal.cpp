/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:13:34 by yokitaga          #+#    #+#             */
/*   Updated: 2024/01/28 10:33:18 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type_("AAnimal") {
	std::cout << "[" << type_ << "] default constructor called at AAnimal.cpp" << std::endl;
}

AAnimal::AAnimal(std::string type) : type_(type) {
	std::cout << "[" << type_ << "] constructor with type called at AAnimal.cpp" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src) {
	*this = src;
	std::cout << "[" << type_ << "] copy constructor called at AAnimal.cpp" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &right) {
	if (this != &right)
		type_ = right.type_;
	std::cout << "[" << type_ << "] assignation operator called at AAnimal.cpp" << std::endl;
	return (*this);
}

AAnimal::~AAnimal() {
	std::cout << "[" << type_ << "] destructor called at AAnimal.cpp" << std::endl;
}

std::string AAnimal::getType() const {
	std::cout << "[" << type_ << "] getType called at AAnimal.cpp" << std::endl;
	return (type_);
}
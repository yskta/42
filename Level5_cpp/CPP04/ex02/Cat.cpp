/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:45:17 by yokitaga          #+#    #+#             */
/*   Updated: 2024/01/28 00:09:51 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat") {
	std::cout << "[" << type_ << "] constructor called at Cat.cpp" << std::endl;
	brain_ = new Brain();
}

Cat::Cat(const Cat &src) : AAnimal(src) {
	*this = src;
	std::cout << "[" << type_ << "] copy constructor called at Cat.cpp" << std::endl;
}

Cat &Cat::operator=(const Cat &right) {
	if (this != &right)
	{
		type_ = right.type_;
		brain_ = new Brain(*right.brain_);
	}
	std::cout << "[" << type_ << "] assignation operator called at Cat.cpp" << std::endl;
	return (*this);
}

Cat::~Cat() {
	delete brain_;
	std::cout << "[" << type_ << "] destructor called at Cat.cpp" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "meow! meow! at Cat.cpp" << std::endl;
}
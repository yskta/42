/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:45:33 by yokitaga          #+#    #+#             */
/*   Updated: 2024/01/28 11:13:09 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "[" << type_ << "] constructor called at Dog.cpp" << std::endl;
	brain_ = new Brain();
}

Dog::Dog(const Dog &src) : Animal(src) {
	*this = src;
	std::cout << "[" << type_ << "] copy constructor called at Dog.cpp" << std::endl;
}

Dog &Dog::operator=(const Dog &right) {
	if (this != &right)
	{
		type_ = right.type_;
		brain_ = new Brain(*right.brain_);
	}
	std::cout << "[" << type_ << "] assignation operator called at Dog.cpp" << std::endl;
	return (*this);
}

Dog::~Dog() {
	delete brain_;
	std::cout << "[" << type_ << "] destructor called at Dog.cpp" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "woof! woof! at Dog.cpp" << std::endl;
}
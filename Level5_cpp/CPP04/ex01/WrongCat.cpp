/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:33:30 by yokitaga          #+#    #+#             */
/*   Updated: 2024/01/28 00:28:24 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "[" << type_ << "] constructor called at WrongCat.cpp" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src) {
	*this = src;
	std::cout << "[" << type_ << "] copy constructor called at WrongCat.cpp" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &right) {
	if (this != &right)
		type_ = right.type_;
	std::cout << "[" << type_ << "] assignation operator called at WrongCat.cpp" << std::endl;
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "[" << type_ << "] destructor called at WrongCat.cpp" << std::endl;
}

//cannnot override
void WrongCat::makeSound() const {
	std::cout << "meow! meow! at WrongCat.cpp" << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:40:53 by yokitaga          #+#    #+#             */
/*   Updated: 2024/01/28 00:25:03 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "[Brain] constructor called" << std::endl;
}

Brain::Brain(const Brain &src) {
	*this = src;
	std::cout << "[Brain] copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &right) {
	if (this != &right)
	{
		for (int i = 0; i < 100; i++)
			this->ideas_[i] = right.ideas_[i];
	}
	std::cout << "[Brain] assignation operator called" << std::endl;
	return (*this);
}

Brain::~Brain() {
	std::cout << "[Brain] destructor called" << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:45:08 by yokitaga          #+#    #+#             */
/*   Updated: 2024/01/28 00:02:35 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
	private:
		Brain *brain_;
	public:
		Dog();
		Dog(const Dog &src);
		Dog &operator=(const Dog &right);
		~Dog();
		void makeSound() const;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:13:38 by yokitaga          #+#    #+#             */
/*   Updated: 2024/01/28 12:11:50 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

//#include <libc.h>
//__attribute__((destructor))
//static void destructor() {
//    system("leaks -q a.out");
//}

int main()
{
	//success delete because of virtual destructor
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~Test1 : success overriding and deleting because of virtual function and virtual destructor~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << "==========success overriding==========" << std::endl;
	meta->makeSound();
	j->makeSound();
	i->makeSound();
	std::cout << "==========success deleting==========" << std::endl;
	delete meta;
	delete j;
	delete i;
	std::cout << "==========Test1 : end==========" << std::endl;
	
	//failed delete because of non-virtual destructor
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~Test2 : fail overriding and deleting because of non-virtual function and non-virtual destructor~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_i = new WrongCat();
	std::cout << wrong_i->getType() << std::endl;
	std::cout << "==========fail overriding==========" << std::endl;
	wrong_i->makeSound();
	wrong_meta->makeSound();
	std::cout << "==========fail deleting==========" << std::endl;
	delete wrong_meta;
	delete wrong_i;//only WrongAnimal destructor called
	std::cout << "==========Test2 : end==========" << std::endl;


	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~Test3 : test about copy constructor and assignation operator~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	Dog dog1;
	Dog dog2(dog1);
	Dog dog3 = dog1;

	Cat cat1;
	Cat cat2(cat1);
	Cat cat3 = cat1;

	std::cout << "dog1: " << dog1.getType() << std::endl;
	std::cout << "dog2: " << dog2.getType() << std::endl;
	std::cout << "dog3: " << dog3.getType() << std::endl;
	std::cout << "cat1: " << cat1.getType() << std::endl;
	std::cout << "cat2: " << cat2.getType() << std::endl;
	std::cout << "cat3: " << cat3.getType() << std::endl;
	std::cout << "==========Test3 : end==========" << std::endl;
	return 0;
}
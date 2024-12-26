/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:13:38 by yokitaga          #+#    #+#             */
/*   Updated: 2024/01/28 11:23:16 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main( void )
{
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~Test 1 : easy test~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
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
    std::cout << "==========Test1:end==========" << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~Test 2: array of Dog and Cat~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    const int arraySize = 6;
    Animal* animalsArray[arraySize];
    
    std::cout << "========add Dog========" << std::endl;
    for (int i = 0; i < arraySize / 2; ++i) {
        animalsArray[i] = new Dog();
    }
    std::cout << "========add Cat========" << std::endl;
    for (int i = arraySize / 2; i < arraySize; ++i) {
        animalsArray[i] = new Cat();
    }
    std::cout << "========delete Dog, Cat========" << std::endl;
    for (int i = 0; i < arraySize; ++i) {
        delete animalsArray[i];
    }
    std::cout << "========Test2:end========" << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~Test 3: deep copy about Dog~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "========create dog1========" << std::endl;
    const Dog* dog1 = new Dog();
    std::cout << "========dog2 = new Dog(*dog1);========" << std::endl;
    const Dog* dog2 = new Dog(*dog1);
    std::cout << "========delete dog1, dog2========" << std::endl;
    delete dog2;
    delete dog1;

    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~Test 4: deep copy about Cat~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "========create cat1========" << std::endl;
    const Cat* cat1 = new Cat();
    std::cout << "========cat2 = new Cat(*cat1);========" << std::endl;
    const Cat* cat2 = new Cat(*cat1);
    std::cout << "========delete cat1, cat2========" << std::endl;
    delete cat2;
    delete cat1;
    std::cout << "========Test4:end========" << std::endl;
    return 0;
}
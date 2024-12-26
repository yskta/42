/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:13:38 by yokitaga          #+#    #+#             */
/*   Updated: 2024/01/28 11:21:02 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main( void )
{
    std::cout << "=============Test 1 : easy test=============" << std::endl;
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
    j->makeSound();
    i->makeSound();
    delete j;//should not create a leak
    delete i;

    //std::cout << "=============Test 2: Instance of AAimal cannot be created because of "pure virtual method 'makeSound' in 'AAnimal'"=============" << std::endl;
    //comment out because of compile error
    //const AAnimal* animal = new AAnimal();

    std::cout << "=============Test 3: array of Dog and Cat=============" << std::endl;
    const int arraySize = 6;
    AAnimal* animalsArray[arraySize];

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
    std::cout << "========Test3:end========" << std::endl;

    std::cout << "=============Test 4: deep copy about Dog=============" << std::endl;
    std::cout << "========create dog1========" << std::endl;
    const Dog* dog1 = new Dog();
    std::cout << "========dog2 = new Dog(*dog1);========" << std::endl;
    const Dog* dog2 = new Dog(*dog1);
    std::cout << "========delete dog1, dog2========" << std::endl;
    delete dog2;
    delete dog1;

    std::cout << "=============Test 5: deep copy about Cat=============" << std::endl;
    std::cout << "========create cat1========" << std::endl;
    const Cat* cat1 = new Cat();
    std::cout << "========cat2 = new Cat(*cat1);========" << std::endl;
    const Cat* cat2 = new Cat(*cat1);
    std::cout << "========delete cat1, cat2========" << std::endl;
    delete cat2;
    delete cat1;
    std::cout << "=============Test5:end=============" << std::endl;
    return 0;
}
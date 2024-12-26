/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:44:23 by yokitaga          #+#    #+#             */
/*   Updated: 2024/01/22 00:00:21 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie;

	std::cout << "[in newZombie:heap] " << std::endl;
	zombie = newZombie("yokitaga on heap");
	zombie->announce();
	delete zombie;
	std::cout << "[in randomChump:stack] " << std::endl;
	randomChump("yokita on stack");
	return (0);
}
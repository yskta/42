/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:27:16 by yokitaga          #+#    #+#             */
/*   Updated: 2024/01/27 00:19:15 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
	std::cout << "===========================test about four functions===========================" << std::endl;
	FragTrap a("Test1");

	//attack
	a.attack("Test2");//FragTrap::attack
	a.ClapTrap::attack("Test2");//ClapTrap::attack
	a.FragTrap::attack("Test2");//FragTrap::attack
	//takeDamage/hit_points 100 → 10
	a.takeDamage(90);
	//beRepaired/hit_points 10 → 20
	a.beRepaired(10);
	//guardGate
	a.highFivesGuys();
	std::cout << "===========================test about hit points===========================" << std::endl;
	//hit_points 20 → 0
	a.takeDamage(20);
	//can't be repaired
	a.beRepaired(10);
	//can't attack
	a.attack("B");
	//can't take damage
	a.takeDamage(10);
	std::cout << "===========================test about energy points===========================" << std::endl;
	FragTrap b("Test2");
	int i = 0;
	//energy_points 100 → 0
	while (i < 100) {
		b.attack("B");
		i++;
	}
	//can't attack
	b.attack("B");
	//cann't be repaired
	b.beRepaired(10);

	std::cout << "===========================test about copy constructor===========================" << std::endl;
	FragTrap c("Test3");
	FragTrap d(c);
	FragTrap e = d;
	//attack
	c.attack("B");
	d.attack("B");
	e.attack("B");
	std::cout << "===========Finish===========" << std::endl;
	return 0;
}
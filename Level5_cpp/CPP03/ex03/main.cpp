/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:27:16 by yokitaga          #+#    #+#             */
/*   Updated: 2024/01/27 00:18:40 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
	std::cout << "===========================test about four functions===========================" << std::endl;
	DiamondTrap a("Test1");

	//attack
	a.attack("Test2");//ScavTrap::attack
	a.ClapTrap::attack("Test2");//ClapTrap::attack
	a.FragTrap::attack("Test2");//FragTrap::attack
	a.ScavTrap::attack("Test2");//ScavTrap::attack
	//takeDamage/hit_points 100 → 10
	a.takeDamage(90);
	//beRepaired/hit_points 10 → 20
	a.beRepaired(10);
	//whoAmI
	a.whoAmI();
	
	std::cout << "===========================test about hit points===========================" << std::endl;
	//hit_points 20 → 0
	a.takeDamage(20);
	//can't be repaired
	a.beRepaired(10);
	//can't attack
	a.attack("B");//ScavTrap::attack
	//can't take damage
	a.takeDamage(10);
	std::cout << "===========================test about energy points===========================" << std::endl;
	DiamondTrap b("Test2");
	int i = 0;
	//energy_points 50 → 0
	while (i < 50) {
		b.attack("B");
		i++;
	}
	//can't attack
	b.attack("B");
	//cann't be repaired
	b.beRepaired(10);
	std::cout << "===========================test about copy constructor and assignation operator===========================" << std::endl;
	DiamondTrap c("Test3");
	DiamondTrap d(c);
	//attack
	d.attack("Test4");
	DiamondTrap e = d;
	//attack
	e.attack("Test5");
	std::cout << "===========Finish===========" << std::endl;
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:04:39 by yokitaga          #+#    #+#             */
/*   Updated: 2024/01/27 00:12:04 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name_(name){
	std::cout << "[DiamondTrap] constructor called" << "[name: " << name_ << "]" << std::endl;
	FragTrap::hit_points_ = 100;
	ScavTrap::energy_points_ = 50;
	FragTrap::attack_damage_ = 30;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "[DiamondTrap] destructor called" << "[name: " << name_ << "]" << std::endl;
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "[DiamondTrap] name: " << name_ << std::endl;
	std::cout << "[ClapTrap] name: " << ClapTrap::name_ << std::endl;
}

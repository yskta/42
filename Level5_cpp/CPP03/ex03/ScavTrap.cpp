/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:24:45 by yokitaga          #+#    #+#             */
/*   Updated: 2024/01/26 22:56:38 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "[ScavTrap] constructor called" << "[name: " << name_ << "]" << std::endl;
	hit_points_ = 100;
	energy_points_ = 50;
	attack_damage_ = 20;
}

ScavTrap::ScavTrap(const ScavTrap &src): ClapTrap(src) {
	*this = src;
	std::cout << "[ScavTrap] copy constructor called" << "[name: " << name_ << "]" << std::endl;
}

ScavTrap&   ScavTrap::operator=( const ScavTrap& right ) {
	if (this != &right) {
		name_ = right.name_;
		hit_points_ = right.hit_points_;
		energy_points_ = right.energy_points_;
		attack_damage_ = right.attack_damage_;
	}
	std::cout << "[ScavTrap] assignation operator called" << "[name: " << name_ << "]" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "[ScavTrap] destructor called" << "[name: " << name_ << "]" << std::endl;
}

void	ScavTrap::attack(const std::string &target) {
	if (energy_points_ == 0) {
		std::cout << "[ScavTrap] " << name_ << " cannot attack because of no energy points." << std::endl;
		return ;
	}
	if (hit_points_ == 0) {
		std::cout << "[ScavTrap] " << name_ << " cannot attack because of no hit points." << name_ << " is dead." << std::endl;
		return ;
	}
	energy_points_--;
	std::cout << "[ScavTrap] " << name_ << " attacks " << target << ", causing " << attack_damage_ << " points of damage!" << energy_points_ << " energy points left." << std::endl;
}

void    ScavTrap::guardGate() {
    std::cout << "[ScavTrap] " << name_ << " is now in Gate keeper mode." << std::endl;
}
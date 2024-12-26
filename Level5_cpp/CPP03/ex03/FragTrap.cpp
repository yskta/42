/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:24:31 by yokitaga          #+#    #+#             */
/*   Updated: 2024/01/26 22:56:31 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "[FragTrap] constructor called" << "[name: " << name_ << "]" << std::endl;
	hit_points_ = 100;
	energy_points_ = 100;
	attack_damage_ = 30;
}

FragTrap::FragTrap(const FragTrap &src): ClapTrap(src) {
	*this = src;
	std::cout << "[FragTrap] copy constructor called" << "[name: " << name_ << "]" << std::endl;
}

FragTrap&   FragTrap::operator=( const FragTrap& right ) {
	if (this != &right) {
		name_ = right.name_;
		hit_points_ = right.hit_points_;
		energy_points_ = right.energy_points_;
		attack_damage_ = right.attack_damage_;
	}
	std::cout << "[FragTrap] assignation operator called" << "[name: " << name_ << "]" << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "[FragTrap] destructor called" << "[name: " << name_ << "]" << std::endl;
}

void	FragTrap::attack(const std::string &target) {
	if (energy_points_ == 0) {
		std::cout << "[FragTrap] " << name_ << " cannot attack because of no energy points." << std::endl;
		return ;
	}
	if (hit_points_ == 0) {
		std::cout << "[FragTrap] " << name_ << " cannot attack because of no hit points." << name_ << " is dead." << std::endl;
		return ;
	}
	energy_points_--;
	std::cout << "[FragTrap] " << name_ << " attacks " << target << ", causing " << attack_damage_ << " points of damage!" << energy_points_ << " energy points left." << std::endl;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "[FragTrap] " << name_ << " wants high five guys." << std::endl;
}
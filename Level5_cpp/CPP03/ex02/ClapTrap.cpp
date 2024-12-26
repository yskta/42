/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:30:11 by yokitaga          #+#    #+#             */
/*   Updated: 2024/01/26 22:53:55 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name_(name), hit_points_(10), energy_points_(10), attack_damage_(0) {
	std::cout << "[ClapTrap] constructor called" << "[name: " << name_ << "]" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
	*this = src;
	std::cout << "[ClapTrap] copy constructor called" << "[name: " << name_ << "]" << std::endl;
}

ClapTrap&   ClapTrap::operator=( const ClapTrap& right ) {
	if (this != &right) {
		name_ = right.name_;
		hit_points_ = right.hit_points_;
		energy_points_ = right.energy_points_;
		attack_damage_ = right.attack_damage_;
	}
	std::cout << "[ClapTrap] assignation operator called" << "[name: " << name_ << "]" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "[ClapTrap] destructor called" << "[name: " << name_ << "]" << std::endl;
}

void	ClapTrap::attack(const std::string &target) {
	if (energy_points_ == 0) {
		std::cout << "[ClapTrap] " << name_ << " cannot attack because of no energy points." << std::endl;
		return ;
	}
	if (hit_points_ == 0) {
		std::cout << "[ClapTrap] " << name_ << " cannot attack because of no hit points." << name_ << " is dead." << std::endl;
		return ;
	}
	energy_points_--;
	std::cout << "[ClapTrap] " << name_ << " attacks " << target << ", causing " << attack_damage_ << " points of damage!" << energy_points_ << " energy points left." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (hit_points_ == 0) {
		std::cout << "[ClapTrap] " << name_ << " has no hit points." <<  name_ << " is dead." << std::endl;
		return ;
	}
	if (amount >= hit_points_)
		hit_points_ = 0;
	else
		hit_points_ -= amount;
	std::cout << "[ClapTrap] " << name_ << " takes " << amount << " points of damage!" << hit_points_ << " hit points left." << std::endl;	
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (energy_points_ == 0) {
		std::cout << "[ClapTrap] " << name_ << " cannot repairs itself because of no energy points. " << std::endl;
		return ;
	}
	if (hit_points_ == 0) {
		std::cout << "[ClapTrap] " << name_ << " cannot repairs itself beacuse of no hit points." << name_ << " is dead." << std::endl;
		return ;
	}
	hit_points_ += amount;
	energy_points_--;
	std::cout << "[ClapTrap] " << name_ << " is repaired " << amount << " hit points." << std::endl;
	std::cout << "[ClapTrap] " << name_ << " has now " << hit_points_ << " hit points and " << energy_points_ << " energy points." << std::endl;
}

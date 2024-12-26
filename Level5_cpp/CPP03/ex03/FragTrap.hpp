/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:28:03 by yokitaga          #+#    #+#             */
/*   Updated: 2024/01/08 17:05:56 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap {
	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap &src);
		FragTrap	&operator=(const FragTrap &right);
		~FragTrap();
		void	attack(const std::string &target);
		void	highFivesGuys(void);
};

#endif
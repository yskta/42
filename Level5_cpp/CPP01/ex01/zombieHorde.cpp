/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:17:47 by yokitaga          #+#    #+#             */
/*   Updated: 2024/01/06 20:20:49 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie  *zombieHorde( int N, std::string name )
{
	Zombie	*zombie;
	int		i;

	zombie = new Zombie[N];
	i = 0;
	while (i < N)
	{
		zombie[i].setName(name);
		i++;
	}
	return (zombie);
}
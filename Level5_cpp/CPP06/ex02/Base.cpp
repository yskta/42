/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:36:00 by yokitaga          #+#    #+#             */
/*   Updated: 2024/02/11 11:04:35 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BaseAndDerived.hpp"

Base *generate(void)
{
	srand (static_cast<unsigned int>(time(NULL)));
	int i = rand() % 3;
	switch (i)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			return (NULL);
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseAndDerived.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:37:31 by yokitaga          #+#    #+#             */
/*   Updated: 2024/02/11 10:56:43 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASEANDDERIVED_HPP
# define BASEANDDERIVED_HPP

# include <iostream>

class Base
{
	public:
		virtual ~Base() {}
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base *generate(void);

#endif
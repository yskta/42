/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:22:06 by yokitaga          #+#    #+#             */
/*   Updated: 2024/02/11 17:43:59 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main()
{
	std::cout << "=========Test1:int=========" << std::endl;
	int x = 5;
	int y = 10;
	std::cout << "x: " << x << "/y: " << y << std::endl;
	::swap(x, y);
	std::cout << "x: " << x << "/y: " << y << std::endl;
	std::cout << "min: " << ::min(x, y) << std::endl;
	std::cout << "max: " << ::max(x, y) << std::endl;
	
	std::cout << "=========Test2:float=========" << std::endl;
	float xf = 5.5f;
	float yf = 10.5f;
	std::cout << "xf: " << xf << "/yf: " << yf << std::endl;
	::swap(xf, yf);
	std::cout << "xf: " << xf << "/yf: " << yf << std::endl;
	std::cout << "min: " << ::min(xf, yf) << std::endl;
	std::cout << "max: " << ::max(xf, yf) << std::endl;

	std::cout << "=========Test3:double=========" << std::endl;
	double xd = 5.2;
	double yd = 10.2;
	std::cout << "xd: " << xd << "/yd: " << yd << std::endl;
	::swap(xd, yd);
	std::cout << "xd: " << xd << "/yd: " << yd << std::endl;
	std::cout << "min: " << ::min(xd, yd) << std::endl;
	std::cout << "max: " << ::max(xd, yd) << std::endl;
	return (0);
}
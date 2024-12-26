/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:03:24 by yokitaga          #+#    #+#             */
/*   Updated: 2024/01/03 00:14:25 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point &src) : _x(src._x), _y(src._y) {}

Point &Point::operator=(const Point &right)
{
	if (this == &right)
		return (*this);
	*this = right;
	return (*this);
}

Point::~Point() {}

Fixed Point::getX() const
{
	return (this->_x);
}

Fixed Point::getY() const
{
	return (this->_y);
}

bool Point::isSame(const Point &point) const
{
	if (this->_x == point._x && this->_y == point._y)
		return (true);
	return (false);
}
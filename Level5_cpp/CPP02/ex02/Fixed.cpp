/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 18:50:31 by yokitaga          #+#    #+#             */
/*   Updated: 2024/01/23 14:17:39 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//constructor&destructor
Fixed::Fixed()
{
	this->fixedPointValue_ = 0;
}

Fixed::Fixed(const int num)
{
	this->fixedPointValue_ = num << this->fractionalBits_;
}

Fixed::Fixed(const float num)
{
	this->fixedPointValue_ = roundf(num * (1 << this->fractionalBits_));
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &right)
{
	if (this != &right)
		this->fixedPointValue_ = right.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
}

//comparisonOperator
bool Fixed::operator>(const Fixed &right) const
{
	if (this->fixedPointValue_ > right.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed &right) const
{
	if (this->fixedPointValue_ < right.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed &right) const
{
	if (this->fixedPointValue_ >= right.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &right) const
{
	if (this->fixedPointValue_ <= right.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed &right) const
{
	if (this->fixedPointValue_ == right.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &right) const
{
	if (this->fixedPointValue_ != right.getRawBits())
		return (true);
	return (false);
}

//arithmeticOperator
Fixed Fixed::operator+(const Fixed &right) const
{
	return (Fixed(this->toFloat() + right.toFloat()));
}

Fixed Fixed::operator-(const Fixed &right) const
{
	return (Fixed(this->toFloat() - right.toFloat()));
}

Fixed Fixed::operator*(const Fixed &right) const
{
	return (Fixed(this->toFloat() * right.toFloat()));
}

Fixed Fixed::operator/(const Fixed &right) const
{
	return (Fixed(this->toFloat() / right.toFloat()));
}

//Increment/decrementOperator
//前置インクリメント
Fixed &Fixed::operator++(void)
{
	this->fixedPointValue_ += 1 << this->fractionalBits_;
	return (*this);
}

//後置インクリメント
//引数 int が渡され、コンパイラはそれを利用して後置インクリメント演算子を呼び出すことを識別
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->fixedPointValue_ += 1 << this->fractionalBits_;
	return (tmp);
}

//前置デクリメント
Fixed &Fixed::operator--(void)
{
	this->fixedPointValue_ -= 1 << this->fractionalBits_;
	return (*this);
}

//後置デクリメント
Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->fixedPointValue_ -= 1 << this->fractionalBits_;
	return (tmp);
}

//min&max
Fixed &Fixed::min(Fixed &left, Fixed &right)
{
	std::cout << "[non const ver min function called]" << std::endl;
	if (left.getRawBits() < right.getRawBits())
		return (left);
	return (right);
}

const Fixed &Fixed::min(const Fixed &left, const Fixed &right)
{
	std::cout << "[const ver min function called]" << std::endl;
	if (left.getRawBits() < right.getRawBits())
		return (left);
	return (right);
}

Fixed &Fixed::max(Fixed &left, Fixed &right)
{
	std::cout << "[non const max function called]" << std::endl;
	if (left.getRawBits() > right.getRawBits())
		return (left);
	return (right);
}

const Fixed &Fixed::max(const Fixed &left, const Fixed &right)
{
	std::cout << "[const ver max function called]" << std::endl;
	if (left.getRawBits() > right.getRawBits())
		return (left);
	return (right);
}

int Fixed::getRawBits(void) const
{
	return (this->fixedPointValue_);
}

void Fixed::setRawBits(int const raw)
{
	this->fixedPointValue_ = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->fixedPointValue_ / (1 << this->fractionalBits_));
}

int Fixed::toInt(void) const
{
	return (this->fixedPointValue_ >> this->fractionalBits_);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

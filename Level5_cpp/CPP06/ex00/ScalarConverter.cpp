/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:08:56 by yokitaga          #+#    #+#             */
/*   Updated: 2024/02/11 10:35:19 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string ScalarConverter::input_;
char ScalarConverter::char_;
int ScalarConverter::int_;
float ScalarConverter::float_;
double ScalarConverter::double_;
bool ScalarConverter::somethingFailed_;
int ScalarConverter::type_;

bool ScalarConverter::isChar()
{
	if (input_.length() == 1 && std::isprint(input_[0]) && !std::isdigit(input_[0]))
		return (true);
	return (false);
}

bool ScalarConverter::isInt()
{
	std::string::size_type i = 0;
	while (std::isspace(input_[i]))
		i++;
	if (input_[i] == '-' || input_[i] == '+')
		i++;
	for (; i < input_.length() ; ++i)
	{
		if (!isdigit(input_[i]))
			return (false);
	}
	return (true);
}

int ScalarConverter::countDots() {
    int dotCount = 0;
    for (std::string::size_type i = 0; i < input_.length(); ++i) {
		char ch = input_[i];
        if (ch == '.') {
            dotCount++;
        }
    }
    return dotCount;
}

bool ScalarConverter::isFloat()
{
	if (input_[input_.length()] != 'f')
		return (false);
	if (countDots() != 1)
		return (false);
	if (input_[0] == '.' || input_[input_.length() - 1] == '.')
		return (false);
	std::string::size_type i = 0;
	while (std::isspace(input_[i]))
		i++;
	if (input_[i] == '-' || input_[i] == '+')
		i++;
	for (; i < input_.length() - 1 ; ++i)
	{
		if (!isdigit(input_[i]) && input_[i] != '.')
			return (false);
	}
	return (true);
}

bool ScalarConverter::isDouble()
{
	if (countDots() != 1)
		return (false);
	if (input_[0] == '.' || input_[input_.length() - 1] == '.')
		return (false);
	std::string::size_type i = 0;
	while (std::isspace(input_[i]))
		i++;
	if (input_[i] == '-' || input_[i] == '+')
		i++;
	for (; i < input_.length() - 1 ; ++i)
	{
		if (!isdigit(input_[i]) && input_[i] != '.')
			return (false);
	}
	return (true);
}

bool ScalarConverter::isSpecialLiteral()
{
	const std::string specialLiteral[6] = {"nan", "nanf", "+inf", "-inf", "+inff", "-inff"};
	for (int i = 0; i < 6; ++i)
	{
		if (input_.compare(specialLiteral[i]) == 0)
			return (true);
	}
	return (false);
}

void ScalarConverter::parseInput()
{
	if (isChar())
		type_ = 0;
	else if (isInt())
		type_ = 1;
	else if (isFloat())
		type_ = 2;
	else if (isDouble())
		type_ = 3;
	else if (isSpecialLiteral())
		type_ = 4;
	else
		type_ = 5;
}

void ScalarConverter::staticCast()
{
	try{
		switch(type_)
		{
			case 0:
				char_ = static_cast<char>(input_[0]);
				int_ = static_cast<int>(char_);
				float_ = static_cast<float>(char_);
				double_ = static_cast<double>(char_);
				break;
			case 1:
				int_ = std::stoi(input_);
				char_ = static_cast<char>(int_);
				float_ = static_cast<float>(int_);
				double_ = static_cast<double>(int_);
				break;
			case 2:
				float_ = std::stof(input_);
				char_ = static_cast<char>(float_);
				int_ = static_cast<int>(float_);
				double_ = static_cast<double>(float_);
				break;
			case 3:
				double_ = std::stod(input_);
				float_ = static_cast<float>(double_);
				char_ = static_cast<char>(double_);
				int_ = static_cast<int>(double_);
				break;
			default:
				break;
		}
	}
	catch(std::out_of_range &e)
	{
		somethingFailed_ = true;
	}
	catch(std::invalid_argument &e)
	{
		somethingFailed_ = true;
	}	
}

void ScalarConverter::printChar() 
{
	if (type_ == 4 || somethingFailed_)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(int_))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << char_ << "'" << std::endl;
}

void ScalarConverter::printInt() 
{
	if (type_ == 4 || somethingFailed_)
		std::cout << "int: impossible" << std::endl;
	else{
		std::cout << "int: " << int_ << std::endl;
	}
}

void ScalarConverter::printFloat() 
{
	if (somethingFailed_)
		std::cout << "float: impossible" << std::endl;
	else if (input_.compare("nanf") == 0 || input_.compare("nan") == 0)
		std::cout << "float: nanf" << std::endl;
	else if (input_.compare("+inf") == 0 || input_.compare("-inf") == 0)
		std::cout << "float: " << input_ << std::endl;
	else if (input_.compare("+inff") == 0)
		std::cout << "float: +inf" << std::endl;
	else if (input_.compare("-inff") == 0)
		std::cout << "float: -inf" << std::endl;
	else{
		if (float_ - roundf(float_) == 0)
			std::cout << "float: " << float_ << ".0f" << std::endl;
		else
			std::cout << "float: " << float_ << "f" << std::endl;
	}
}

void ScalarConverter::printDouble()
{
	if (somethingFailed_)
		std::cout << "double: impossible" << std::endl;
	else if (input_.compare("nanf") == 0 || input_.compare("nan") == 0)
		std::cout << "double: nan" << std::endl;
	else if (input_.compare("+inff") == 0 || input_.compare("-inff") == 0)
		std::cout << "double: " << input_ << std::endl;
	else if (input_.compare("+inf") == 0)
		std::cout << "double: +inff" << std::endl;
	else if (input_.compare("-inf") == 0)
		std::cout << "double: -inff" << std::endl;
	else{
		if (double_ - round(double_) == 0)
			std::cout << "double: " << double_ << ".0" << std::endl;
		else
			std::cout << "double: " << double_ << std::endl;
	}
}

void ScalarConverter::printAll()
{
	printChar();
	printInt();
	printFloat();
	printDouble();
}

int ScalarConverter::getType() 
{
	return (type_);
}

void ScalarConverter::setInput(const std::string& input)
{
	input_ = input;
}

void ScalarConverter::scalarConverter(const std::string& input)
{
	setInput(input);
	parseInput();
	staticCast();
	printAll();
}

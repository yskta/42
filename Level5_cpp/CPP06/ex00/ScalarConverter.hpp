/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:08:58 by yokitaga          #+#    #+#             */
/*   Updated: 2024/02/11 10:12:58 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>

//todo 関数はstaticにする。あとは基本privateにする。convertだけpublicにする。
class ScalarConverter
{
	private:
		static std::string	input_;
		static char			char_;
		static int			int_;
		static float		float_;
		static double		double_;
		static bool			somethingFailed_;

		static int 			type_;

		static int 			countDots();
		static bool 		isChar();
		static bool 		isInt();
		static bool 		isFloat();
		static bool 		isDouble();
		static bool 		isSpecialLiteral();
		static void 		parseInput();

		static void 		staticCast();
		
		static void 		printChar();
		static void 		printInt();
		static void 		printFloat();
		static void 		printDouble();
		static void 		printAll();
		
		static void 		setInput(const std::string& input);
		static int			getType();
		
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &right);
		~ScalarConverter();
	public:
		static void			scalarConverter(const std::string& input);
};

#endif
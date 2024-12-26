/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:08:53 by yokitaga          #+#    #+#             */
/*   Updated: 2024/02/11 10:01:35 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	//if (argc != 2)
	//{
	//	std::cerr << "Invalid argments. Please Input like ./conver something." << std::endl;
	//	return (EXIT_FAILURE);
	//}
	//ScalarConverter ScalarConvert(argv[1]);
	//int i = ScalarConvert.getType();
	//std::cout << i << std::endl;
	//std::cout << ScalarConvert;
	(void) argc;
	(void) argv;
	//test case
	std::cout << "=====test case1=====" << std::endl;
	ScalarConverter::scalarConverter("0");
	std::cout << "=====test case2=====" << std::endl;
	ScalarConverter::scalarConverter("0.0");
	std::cout << "=====test case3=====" << std::endl;
	ScalarConverter::scalarConverter("0.0f");
	std::cout << "=====test case4=====" << std::endl;
	ScalarConverter::scalarConverter("42.0f");
	std::cout << "=====test case5=====" << std::endl;
	ScalarConverter::scalarConverter("42.0");
	std::cout << "=====test case6=====" << std::endl;
	ScalarConverter::scalarConverter("nan");
	std::cout << "=====test case7=====" << std::endl;
	ScalarConverter::scalarConverter("nanf");
	std::cout << "=====test case8=====" << std::endl;
	ScalarConverter::scalarConverter("+inf");
	std::cout << "=====test case9=====" << std::endl;
	ScalarConverter::scalarConverter("+inff");
	std::cout << "=====test case10=====" << std::endl;
	ScalarConverter::scalarConverter("-inf");
	std::cout << "=====test case11=====" << std::endl;
	ScalarConverter::scalarConverter("-inff");
	std::cout << "=====test case12=====" << std::endl;
	ScalarConverter::scalarConverter("a");
	std::cout << "=====test case13=====" << std::endl;
	ScalarConverter::scalarConverter("aaa");
	std::cout << "=====test case14 intMax=====" << std::endl;
	ScalarConverter::scalarConverter("2147483647");
	std::cout << "=====test case15 intMin=====" << std::endl;
	ScalarConverter::scalarConverter("-2147483648");
	std::cout << "=====test case16 floatMax=====" << std::endl;
	ScalarConverter::scalarConverter("340282346638528859811704183484516925440.0f");
	std::cout << "=====test case17 floatMin=====" << std::endl;
	ScalarConverter::scalarConverter("-340282346638528859811704183484516925440.0f");
	std::cout << "=====test case18 doubleMax=====" << std::endl;
	ScalarConverter::scalarConverter("179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0");
	std::cout << "=====test case19 doubleMin=====" << std::endl;
	ScalarConverter::scalarConverter("-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0");
	return (0);
}
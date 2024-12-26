/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:12:01 by yokitaga          #+#    #+#             */
/*   Updated: 2024/01/06 16:24:45 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char* argv[])
{
	if (argc == 1){
		std::cerr << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 1;
	}

	for (int i = 1; i < argc; i++){
		std::string input =  argv[i];
		for (size_t j = 0; j < input.length(); j++){
			std::cout << (char)toupper(input[j]);
		}
	}
	std::cout << std::endl;
	return 0;
}

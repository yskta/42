/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:09:27 by yokitaga          #+#    #+#             */
/*   Updated: 2024/01/07 15:09:31 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>

class sed
{
	private:
		std::string _inputFileName;
		std::string _outputFileName;
	public:
		sed(std::string filename);
		~sed();
		void replace(std::string s1, std::string s2);
};

#endif
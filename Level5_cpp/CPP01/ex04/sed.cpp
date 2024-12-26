/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:09:32 by yokitaga          #+#    #+#             */
/*   Updated: 2024/01/07 15:32:54 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

sed::sed(std::string filename): _inputFileName(filename), _outputFileName(filename + ".replace")
{
}

sed::~sed()
{
}

void sed::replace(std::string s1, std::string s2)
{
	std::ifstream ifs(_inputFileName);
	std::ofstream ofs(_outputFileName);
	
    if (!ifs.is_open() || !ofs.is_open()) {
		std::cerr << "Error: file open failed" << std::endl;
        exit(1);
    }
	
	std::string allContent;
	std::getline(ifs, allContent, '\0');
    size_t pos;//posにはs1の最初の文字が見つかった位置が入る。nposはみつからなかったときの定数
    while ((pos = allContent.find(s1)) != std::string::npos) {
        allContent.erase(pos, s1.length());
		allContent.insert(pos, s2);
    }
    ofs << allContent;
}
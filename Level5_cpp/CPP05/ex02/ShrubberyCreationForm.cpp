/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:08:28 by yokitaga          #+#    #+#             */
/*   Updated: 2024/02/04 12:46:22 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():Form("ShrubberyCreationForm", 145, 137), target_("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : Form("ShrubberyCreationForm", 145, 137), target_(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : Form(src)
{
	*this = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &right)
{
	if(this != &right){
		this->target_ = right.target_;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (getSigned() == false)
		throw Form::FormIsSignedCheck();
	else if (executor.getGrade() > getGradeToExecute())
		throw Form::GradeTooLowException();
	std::string fileName = target_ + "_shrubbery";
	std::ofstream file(fileName);
	if (file.is_open()) {
        file << "   *\n";
        file << "  ***\n";
        file << " *****\n";
        file << "*******\n";
        file << "  |||\n";
        std::cout << "Shrubbery created in file: " <<  fileName << std::endl;
        file.close();
    } else {
        std::cerr << "Error creating file: " << fileName << std::endl;
    }
}
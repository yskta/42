/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 01:27:08 by yokitaga          #+#    #+#             */
/*   Updated: 2024/02/04 15:43:06 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &src)
{
	*this = src;
}

Intern &Intern::operator=(const Intern &right)
{
	if (this != &right){
		(void)right;
	}
	return (*this);
}

Intern::~Intern()
{
}

Form *Intern::makeForm(const std::string &formName, const std::string &target)
{
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Form *forms[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
	for (int i = 0; i < 3; i++)
	{
		if (formName.compare(formNames[i]) == 0)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (forms[i]);
		}
	}
	std::cout << "Intern cannot create " << formName << " because it is not a valid form name." << std::endl;
	return (NULL);
}

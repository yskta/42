/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:10:29 by yokitaga          #+#    #+#             */
/*   Updated: 2024/02/04 12:02:46 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():Form("RobotomyRequestForm", 72, 45), target_("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : Form("RobotomyRequestForm", 72, 45), target_(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : Form(src)
{
	*this = src;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &right)
{
	if(this != &right){
		this->target_ = right.target_;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (getSigned() == false)
		throw Form::FormIsSignedCheck();
	else if (executor.getGrade() > getGradeToExecute())
		throw Form::GradeTooLowException();
	std::cout << "Bzzzzzz........" << std::endl;
	std::srand(static_cast<unsigned int>(time(NULL)));
	if (std::rand() % 2 == 0)
		std::cout << target_ << " has been robotomized successfully." << std::endl;
	else
		std::cout << target_ << " robotomization failed." << std::endl;
}
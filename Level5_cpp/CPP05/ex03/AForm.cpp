/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:07:47 by yokitaga          #+#    #+#             */
/*   Updated: 2024/02/04 12:53:01 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

Form::Form() : name_("default"), isSigned_(false), gradeToSign_(150), gradeToExecute_(150)
{
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) : name_(name), gradeToSign_(gradeToSign), gradeToExecute_(gradeToExecute)
{
	if (gradeToSign < MAXgrade || gradeToExecute < MAXgrade)
		throw Form::GradeTooHighException();
	else if (gradeToSign > MINgrade || gradeToExecute > MINgrade)
		throw Form::GradeTooLowException();
	else{
		isSigned_ = false;
	}
}

Form::Form(const Form &src) : name_(src.name_), gradeToSign_(src.gradeToSign_), gradeToExecute_(src.gradeToExecute_)
{
	*this = src;
}

Form &Form::operator=(const Form &right)
{
	if (this != &right){
		isSigned_ = right.isSigned_;
	}
	return (*this);
}

Form::~Form()
{
}

const std::string Form::getName() const
{
	return (name_);
}

bool	Form::getSigned() const
{
	return (isSigned_);
}

int		Form::getGradeToSign() const
{
	return (gradeToSign_);
}

int		Form::getGradeToExecute() const
{
	return (gradeToExecute_);
}

void	Form::beSigned(const Bureaucrat &src)
{
	if (src.getGrade() > gradeToSign_)
		throw Form::GradeTooLowException();
	else {
		isSigned_ = true;
	}
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too High in Form.cpp.");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low in Form.cpp.");
}

const char *Form::FormIsSignedCheck::what() const throw()
{
	return ("this form is not signed.");
}

std::ostream &operator<<(std::ostream &out, const Form &right)
{
    out << "-----[Form Infomation]-----" << std::endl
        << "[Form name]: " << right.getName() << std::endl
        << "[Required grade to sign]: " << right.getGradeToSign() << std::endl
        << "[Required grade to execute]: " << right.getGradeToExecute() << std::endl;
	out << "---------------------------" << std::endl;
    return out;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:55:42 by yokitaga          #+#    #+#             */
/*   Updated: 2024/02/03 18:49:45 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("default"), grade_(150)
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name_(name)
{
	if (grade < MAXgrade)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > MINgrade)
		throw Bureaucrat::GradeTooLowException();
	else
		grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name_(src.name_)//name_はconstなのでコピーできない
{
	*this = src;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &right)
{
	if (this != &right){
		grade_ = right.grade_;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

const std::string Bureaucrat::getName() const
{
	return (name_);
}

int Bureaucrat::getGrade() const
{
	return (grade_);
}

void Bureaucrat::incrementGrade()
{
	if (grade_ - 1 < MAXgrade)
		throw Bureaucrat::GradeTooHighException();
	else
		grade_--;
}

void Bureaucrat::decrementGrade()
{
	if (grade_ + 1 > MINgrade)
		throw Bureaucrat::GradeTooLowException();
	else
		grade_++;
}

void Bureaucrat::signForm(Form &form)
{
	try {
        form.beSigned( *this );
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    } catch (Form::GradeTooLowException &e) {
        std::cout << this->getName() << " coulnd't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too High in Bureaucrat.cpp.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low in Bureaucrat.cpp.");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &right)
{
	out << right.getName() << ", bureaucrat grade " << right.getGrade() << std::endl;
	return (out);
}
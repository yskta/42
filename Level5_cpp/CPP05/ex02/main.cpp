/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:55:19 by yokitaga          #+#    #+#             */
/*   Updated: 2024/02/04 12:54:30 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    std::cout << "================Test1:ShrubberyCreationForm================" << std::endl;
    Bureaucrat bureaucrat("Test1", 146);
    ShrubberyCreationForm form1("Form1");
    std::cout << form1;
    //cannnot execute because not signed
    bureaucrat.executeForm(form1);
    //cannnot sign because grade is too low for sign
    bureaucrat.signForm(form1);
    bureaucrat.incrementGrade();
    //success to sign
    bureaucrat.signForm(form1);
    //cannnot execute because grade is too low for execute
    bureaucrat.executeForm(form1);
    for (int i = 0; i < 9; i++)
        bureaucrat.incrementGrade();
    bureaucrat.executeForm(form1);
    
    std::cout << "================Test2:RobotomyRequestForm================" << std::endl;
    Bureaucrat bureaucrat2("Test2", 73);
    RobotomyRequestForm form2("Form2");
    std::cout << form2;
    //cannnot execute because not signed
    bureaucrat2.executeForm(form2);
    //cannnot sign because grade is too low for sign
    bureaucrat2.signForm(form2);
    bureaucrat2.incrementGrade();
    //success to sign
    bureaucrat2.signForm(form2);
    //cannnot execute because grade is too low for execute
    bureaucrat2.executeForm(form2);
    for (int i = 0; i < 27; i++)
        bureaucrat2.incrementGrade();
    //success to execute
    bureaucrat2.executeForm(form2);
    std::cout << "================Test3:PresidentialPardonForm================" << std::endl;
    Bureaucrat bureaucrat3("Test3", 26);
    PresidentialPardonForm form3("Form3");
    std::cout << form3;
    //cannnot execute because not signed
    bureaucrat3.executeForm(form3);
    //cannnot sign because grade is too low for sign
    bureaucrat3.signForm(form3);
    bureaucrat3.incrementGrade();
    //success to sign
    bureaucrat3.signForm(form3);
    //cannnot execute because grade is too low for execute
    bureaucrat3.executeForm(form3);
    for (int i = 0; i < 20; i++)
        bureaucrat3.incrementGrade();
    //success to execute
    bureaucrat3.executeForm(form3);
	return (0);
}
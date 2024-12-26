/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:55:19 by yokitaga          #+#    #+#             */
/*   Updated: 2024/02/04 11:49:04 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    std::cout << "================[Form]Test1:easy test================" << std::endl;
    Bureaucrat bureaucrat("Test1", 5);
    Form form("Form1", 4, 4);
    bureaucrat.signForm(form);
    bureaucrat.incrementGrade();
    bureaucrat.signForm(form);
    bureaucrat.decrementGrade();
    bureaucrat.signForm(form);
    std::cout << form;
    
    std::cout << "================[Form]Test2:Too low================" << std::endl;
    try {
        Bureaucrat bureaucrat("Test2", 150);
        Form form("Form2", 151, 151);
        bureaucrat.signForm(form);
        std::cout << form;
    } catch (std::exception &e) {
        std::cout << "Exception Catch: " << e.what() << std::endl;
    }
    std::cout << "================[Form]Test3:Too high================" << std::endl;
    try {
        Bureaucrat bureaucrat("Test3", 1);
        Form form("Form3", 0, 0);
        bureaucrat.signForm(form);
        std::cout << form;
    } catch (std::exception &e) {
        std::cout << "Exception Catch: " << e.what() << std::endl;
    }
    std::cout << "================[Form]Test4:Copy and Assign operator================" << std::endl;
    Form form4("Form4", 4, 4);
    Form form2(form);
    Form form3 = form;
    std::cout << form2;
    std::cout << form3;
	return (0);
}
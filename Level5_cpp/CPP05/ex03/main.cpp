/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:55:19 by yokitaga          #+#    #+#             */
/*   Updated: 2024/02/04 15:52:09 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
    std::cout << "================Test1: shrubbery creation================" << std::endl;
    Intern someRandomIntern;
    Form* rrf1;
    rrf1 = someRandomIntern.makeForm("shrubbery creation", "Bender");
    Bureaucrat b1("Bureaucrat1", 1);
    b1.signForm(*rrf1);
    b1.executeForm(*rrf1);
    delete rrf1;
    std::cout << "================Test2: robotomy request================" << std::endl;
    Form* rrf2 = someRandomIntern.makeForm("robotomy request", "Bender");
    Bureaucrat b2("Bureaucrat2", 1);
    b2.signForm(*rrf2);
    b2.executeForm(*rrf2);
    delete rrf2;
    std::cout << "================Test3: presidential pardon================" << std::endl;
    Form* rrf3 = someRandomIntern.makeForm("presidential pardon", "Bender");
    Bureaucrat b3("Bureaucrat3", 1);
    b3.signForm(*rrf3);
    b3.executeForm(*rrf3);
    delete rrf3;
    std::cout << "================Test4: invalid form name================" << std::endl;
    Form* rrf4 = someRandomIntern.makeForm("invalid form name", "Bender");
    if (rrf4 != NULL)
    {
        Bureaucrat b4("Bureaucrat4", 1);
        b4.signForm(*rrf4);
        b4.executeForm(*rrf4);
        delete rrf4;
    }
	return (0);
}
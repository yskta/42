/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:55:19 by yokitaga          #+#    #+#             */
/*   Updated: 2024/02/03 19:03:25 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat *bureaucrat;
	std::cout << "================[Bureaucrat]Test1 about Too high================" << std::endl;
	try
	{
		bureaucrat = new Bureaucrat("Test1", 1);
		std::cout << *bureaucrat;
		bureaucrat->decrementGrade();
		std::cout << *bureaucrat;
		bureaucrat->decrementGrade();
		std::cout << *bureaucrat;
		bureaucrat->incrementGrade();
		std::cout << *bureaucrat;
		bureaucrat->incrementGrade();
		std::cout << *bureaucrat;
		bureaucrat->incrementGrade();
		std::cout << *bureaucrat;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete bureaucrat;
	std::cout << "================[Bureaucrat]Test2 about Too Low================" << std::endl;
	try
	{
		bureaucrat = new Bureaucrat("Test2", 150);
		std::cout << *bureaucrat;
		bureaucrat->incrementGrade();
		std::cout << *bureaucrat;
		bureaucrat->incrementGrade();
		std::cout << *bureaucrat;
		bureaucrat->decrementGrade();
		std::cout << *bureaucrat;
		bureaucrat->decrementGrade();
		std::cout << *bureaucrat;
		bureaucrat->decrementGrade();
		std::cout << *bureaucrat;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete bureaucrat;
	std::cout << "================[Bureaucrat]Test3 about copy and assign================" << std::endl;
	Bureaucrat *Bureaucrat1 = new Bureaucrat("Test3", 1);
	Bureaucrat *Bureaucrat2 = Bureaucrat1;
	Bureaucrat *Bureaucrat3(Bureaucrat1);
	std::cout << *Bureaucrat2;
	std::cout << *Bureaucrat3;
	delete Bureaucrat1;
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:07:42 by yokitaga          #+#    #+#             */
/*   Updated: 2024/02/04 15:48:53 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string name_;
		bool isSigned_;
		const int gradeToSign_;
		const int gradeToExecute_;
		Form();
	public:
		Form(const std::string &name, int gradeToSign, int gradeToExecute);
		Form(const Form &src);
		Form &operator=(const Form &right); 
		virtual ~Form();

		const std::string getName() const;
		bool	getSigned() const;
    	int		getGradeToSign() const;
    	int		getGradeToExecute() const;

		void	beSigned(const Bureaucrat &src);
		

		virtual void execute(const Bureaucrat &executor) const = 0;

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class FormIsSignedCheck : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream&   operator<<( std::ostream& out, const Form& right );

#endif
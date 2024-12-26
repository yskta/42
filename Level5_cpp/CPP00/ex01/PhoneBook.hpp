/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:32:43 by yokitaga          #+#    #+#             */
/*   Updated: 2024/01/19 23:55:25 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# ifndef MAX_CONTACTS
#  define MAX_CONTACTS 8
# endif

#include "Contact.hpp"
#include <cstdlib>

class PhoneBook
{
	private:
		int		currentIndex;
		Contact contacts[MAX_CONTACTS];
	public:
		PhoneBook();
		~PhoneBook();
		void	add();
		int		getLastIndex()const;
		void	displayAll()const;
		void	search()const;
		void	exit()const;
};

#endif
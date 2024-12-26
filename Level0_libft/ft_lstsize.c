/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:06:32 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/16 17:36:10 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//lst：the beginning of list
int ft_lstsize(t_list *lst)
{
    int size;

    size = 0;
    if (lst == NULL)
        return (size);
    while (lst->next != NULL)
    {
        lst = lst->next;
        size++;
    }
    return(size);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:06:07 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/16 18:01:39 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_lstadd_front(t_list **lst, t_list *new)
{
    
    if (new == NULL)
        return ;
    if (*lst != NULL)
        ft_lstlast(new)->next = *lst;
    *lst = new;
}
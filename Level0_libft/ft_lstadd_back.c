/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:06:03 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/16 18:02:40 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_lstadd_back(t_list **lst, t_list *new)
{
    if (new == NULL)
        return ;
    if (*lst == NULL)
    {
        *lst = new;
        return ;
    }
    ft_lstlast(*lst)->next = new;
}
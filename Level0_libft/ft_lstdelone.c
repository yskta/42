/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:06:14 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/16 18:11:50 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_lstdelone(t_list *lst, void (*del)(void*))
{
    if (lst == NULL)
        return ;
    if (del != NULL && lst->content != NULL)
		del(lst->content);
	free(lst);
}
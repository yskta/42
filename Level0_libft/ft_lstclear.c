/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:06:11 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/16 18:19:33 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list		*next_node;
	t_list		*cur_node;

	if (lst == NULL)
		return ;
	cur_node = *lst;
	while (cur_node != NULL)
	{
		next_node = cur_node->next;
		ft_lstdelone(cur_node, del);
		cur_node = next_node;
	}
	*lst = NULL;
}
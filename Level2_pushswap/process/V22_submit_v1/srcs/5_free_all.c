/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_free_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:54:38 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/27 01:55:26 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack_and_data(t_data *data)
{
	t_node	*current;
	t_node	*next;

	if (data->stack_malloc == true)
	{
		current = data->stack_a;
		while (current->end == false)
		{
			next = current->next;
			free(current);
			current = next;
		}
		free(current);
	}
	free(data);
}

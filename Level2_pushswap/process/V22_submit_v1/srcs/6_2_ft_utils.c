/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_1_ft_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:44:13 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/27 02:11:28 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	find_max_sorted_index(t_node **stack)
{
	size_t	max_sorted_index;
	t_node	*current;

	current = *stack;
	max_sorted_index = current->sorted_index;
	while (current->end == false)
	{
		if (max_sorted_index < current->sorted_index)
			max_sorted_index = current->sorted_index;
		current = current->next;
	}
	if (max_sorted_index < current->sorted_index)
		max_sorted_index = current->sorted_index;
	return (max_sorted_index);
}

size_t	find_next_sorted_index_pos(t_node **stack, size_t index)
{
	t_node	*current;
	size_t	prev_sorted_index;
	size_t	next_sorted_index;
	size_t	next_sorted_index_pos;

	current = *stack;
	prev_sorted_index = current->prev->sorted_index;
	next_sorted_index = current->sorted_index;
	next_sorted_index_pos = 0;
	while (current->end == false)
	{
		prev_sorted_index = current->prev->sorted_index;
		next_sorted_index = current->sorted_index;
		if (prev_sorted_index < index && index < next_sorted_index)
			break ;
		next_sorted_index_pos++;
		current = current->next;
	}
	return (next_sorted_index_pos);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_2_sort_7_or_more.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 03:49:10 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/27 04:51:42 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_7_or_more(t_data *data)
{
	size_t	min_pos;

	quick_sort_ops(data);
	push_back(data, &(data->stack_b));
	min_pos = find_min_pos(&(data->stack_a), 0);
	while (data->stack_a->sorted_index != 0)
	{
		if (min_pos < data->stack_len / 2)
			operation_ra(data);
		else
			operation_rra(data);
	}
	min_pos = find_min_pos(&(data->stack_a), 0);
	while (data->stack_a->sorted_index != 0)
	{
		if (min_pos < data->stack_len / 2)
			operation_ra(data);
		else
			operation_rra(data);
	}
}

void	quick_sort(t_data *data, size_t index_1)
{
	t_node	*current;
	size_t	i;
	size_t	stack_a_len;

	stack_a_len = ft_stack_size(data->stack_a);
	i = 0;
	current = data->stack_a;
	while (i < stack_a_len)
	{
		if (current->sorted_index >= index_1)
			operation_pb(data);
		else
			operation_ra(data);
		current = data->stack_a;
		i++;
	}
}

void	quick_sort_ops(t_data *data)
{
	if (data->stack_len > 100)
		quick_sort(data, data->index_eleventh);
	quick_sort(data, data->index_tenth);
	if (data->stack_len > 100)
		quick_sort(data, data->index_nineth);
	quick_sort(data, data->index_eigth);
	if (data->stack_len > 100)
		quick_sort(data, data->index_seventh);
	quick_sort(data, data->index_sixth);
	if (data->stack_len > 100)
		quick_sort(data, data->index_fifth);
	quick_sort(data, data->index_forth);
	if (data->stack_len > 100)
		quick_sort(data, data->index_third);
	quick_sort(data, data->index_second);
	if (data->stack_len > 100)
		quick_sort(data, data->index_first);
	quick_sort(data, 0);
}

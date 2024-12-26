/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_3_sort_7_or_more.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 04:45:39 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/27 04:57:58 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back_pa(t_data *data, t_cost *cost)
{
	size_t	i;

	i = 0;
	if (cost->ra != 0)
	{
		while (i < cost->ra)
		{
			operation_ra(data);
			i++;
		}
	}
	i = 0;
	if (cost->rra != 0)
	{
		while (i < cost->rra)
		{
			operation_rra(data);
			i++;
		}
	}
	operation_pa(data);
}

t_cost	calc_cost_in_codition1(t_data *data, size_t stack_a_size)
{
	t_cost	cost;

	cost.ra = 0;
	cost.rra = 0;
	data->min_pos = find_min_pos(&(data->stack_a), \
			data->min_sorted_index_at_stack_a);
	if (data->min_pos < stack_a_size / 2)
		cost.ra = data->min_pos;
	else
		cost.rra = stack_a_size - data->min_pos;
	return (cost);
}

t_cost	calc_cost_in_codition2(t_data *data, \
		t_node *current, size_t stack_a_size)
{
	t_cost	cost;

	cost.ra = 0;
	cost.rra = 0;
	data->next_sorted_index_pos = find_next_sorted_index_pos(&(data->stack_a), \
			current->sorted_index);
	if (data->next_sorted_index_pos < stack_a_size / 2)
		cost.ra = data->next_sorted_index_pos;
	else
		cost.rra = stack_a_size - data->next_sorted_index_pos;
	return (cost);
}

t_cost	calc_cost(t_data *data, t_node *current)
{
	t_cost	cost;
	size_t	stack_a_size;

	cost.ra = 0;
	cost.rra = 0;
	stack_a_size = 0;
	stack_a_size = ft_stack_size(data->stack_a);
	if (stack_a_size < 2)
		return (cost);
	data->min_sorted_index_at_stack_a = find_min_sorted_index(&(data->stack_a));
	data->max_sorted_index_at_stack_a = find_max_sorted_index(&(data->stack_a));
	if (current->sorted_index < data->min_sorted_index_at_stack_a || \
			current->sorted_index > data->max_sorted_index_at_stack_a)
		cost = calc_cost_in_codition1(data, stack_a_size);
	else
		cost = calc_cost_in_codition2(data, current, stack_a_size);
	return (cost);
}

void	push_back(t_data *data, t_node **stack_b)
{
	t_node	*current;
	t_cost	cost;

	current = *stack_b;
	while (current != NULL)
	{
		cost.ra = 0;
		cost.rra = 0;
		cost = calc_cost(data, current);
		push_back_pa(data, &cost);
		current = *stack_b;
	}
}

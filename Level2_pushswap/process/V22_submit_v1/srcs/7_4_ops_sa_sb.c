/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_4_ops_sa_sb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:22:51 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/27 01:52:16 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_or_sb(t_node **stack_head)
{
	t_node	*current;
	t_node	*next;

	if (stack_head == NULL || *stack_head == NULL)
		return ;
	current = *stack_head;
	if (current->end == true)
		return ;
	next = current->next;
	if (ft_stack_size(*stack_head) > 2)
	{
		next->prev = current->prev;
		current->next = next->next;
		current->prev->next = next;
		next->next->prev = current;
	}
	current->prev = next;
	next->next = current;
	if (next->end == true)
	{
		next->end = false;
		current->end = true;
	}
	*stack_head = next;
}

void	operation_sa(t_data *data)
{
	sa_or_sb(&(data->stack_a));
	ft_printf("sa\n");
}

void	operation_sb(t_data *data)
{
	sa_or_sb(&(data->stack_b));
	ft_printf("sb\n");
}

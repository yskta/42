/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_3_ops_rra_rrb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:39:27 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/27 01:46:53 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_or_rrb(t_node **stack_head)
{
	if (stack_head == NULL)
		return ;
	if (*stack_head == NULL)
		return ;
	(*stack_head)->prev->end = false;
	(*stack_head)->prev->prev->end = true;
	*stack_head = (*stack_head)->prev;
}

void	operation_rra(t_data *data)
{
	rra_or_rrb(&(data->stack_a));
	ft_printf("rra\n");
}

void	operation_rrb(t_data *data)
{
	rra_or_rrb(&(data->stack_b));
	ft_printf("rrb\n");
}

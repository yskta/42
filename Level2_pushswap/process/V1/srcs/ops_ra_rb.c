/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_ra_rb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:38:31 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/20 13:41:50 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra_or_rb(t_node **stack_head)
{
    if(stack_head==NULL)
        return ;
    if(*stack_head==NULL)
        return ;
    (*stack_head)->prev->end=false;
    (*stack_head)->end=true;
    *stack_head=(*stack_head)->next;
}

void operation_ra(t_data *data)
{
    ra_or_rb(&(data->stack_a));
}

void operation_rb(t_data *data)
{
    ra_or_rb(&(data->stack_b));
}
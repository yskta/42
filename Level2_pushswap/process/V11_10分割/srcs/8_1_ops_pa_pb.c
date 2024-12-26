/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_pa_pb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:40:47 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/23 16:47:23 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *pop(t_node **stack_head)
{
    t_node *prev;
    t_node *next;
    t_node *current;

    if(stack_head==NULL)
        return(NULL);
    if(*stack_head==NULL)
        return(NULL);
    current = *stack_head;
    prev=current->prev;
    next=current->next;
    prev->next=next;
    next->prev=prev;
    if (current->end==false)
        *stack_head = next;
    else
        *stack_head = NULL;
    current->end = false;
    return (current);
}

void operation_pa(t_data *data)
{
    t_node *top;

    top = pop(&(data->stack_b));
    if (top == NULL)
        return ;
    ft_stack_add_front(&(data->stack_a), top);
    printf("pa\n");
    data->count++;
}

void operation_pb(t_data *data)
{
    t_node *top;

    top = pop(&(data->stack_a));
    if (top == NULL)
        return ;
    ft_stack_add_front(&(data->stack_b), top);
    printf("pb\n");
    data->count++;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_sort_6_or_less.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:06:20 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/26 17:11:08 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_3_or_less(t_data *data, t_node *stack)
{
    t_node *current;
    
    current = stack;
    if (data->stack_len == 2)
    {
        operation_sa(data);
        return ;
    }
    if (current->value <  current->next->value)
    {
        operation_rra(data);
        if (confirm_sorted(&(data->stack_a)) == false)
            operation_sa(data); 
    }
    else if (current->next->value < current->next->next->value)
    {
        if (current->value < current->next->next->value)
            operation_sa(data);
        else
            operation_ra(data);
    }
    else
    {
        operation_ra(data);
        operation_sa(data);
    }
}

void sort_4(t_data *data)
{
    size_t min_sorted_index;
    size_t min_pos;
    t_node *head;
    
    head = data->stack_a;
    min_sorted_index = find_min_sorted_index(&head);
    min_pos = find_min_pos(&head, min_sorted_index);
    while (head->sorted_index != min_sorted_index)
    {
        if (min_pos < data->stack_len / 2)
            operation_ra(data);
        else
            operation_rra(data);
        head = data->stack_a;
    }
    operation_pb(data);
    if (confirm_sorted(&(data->stack_a)) == false)
        sort_3_or_less(data, data->stack_a);
    operation_pa(data);
}

void sort_5(t_data *data)
{
    size_t min_sorted_index;
    size_t min_pos;
    t_node *head;
    
    head = data->stack_a;
    min_sorted_index = find_min_sorted_index(&head);
    min_pos = find_min_pos(&head, min_sorted_index);
    while (head->sorted_index != min_sorted_index)
    {
        if (min_pos < data->stack_len / 2)
            operation_ra(data);
        else
            operation_rra(data);
        head = data->stack_a;
    }
    operation_pb(data);
    if (confirm_sorted(&(data->stack_a)) == false)
        sort_4(data);
    operation_pa(data);
}

void sort_6(t_data *data)
{
    size_t min_sorted_index;
    size_t min_pos;
    t_node *head;
    
    head = data->stack_a;
    min_sorted_index = find_min_sorted_index(&head);
    min_pos = find_min_pos(&head, min_sorted_index);
    while (head->sorted_index != min_sorted_index)
    {
        if (min_pos < data->stack_len / 2)
            operation_ra(data);
        else
            operation_rra(data);
        head = data->stack_a;
    }
    operation_pb(data);
    if (confirm_sorted(&(data->stack_a)) == false)
        sort_5(data);
    operation_pa(data);
}
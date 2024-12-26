/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_sort_7_or_more.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:50:45 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/25 17:26:58 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void push_back_pa(t_data *data, t_cost *cost)
{
    size_t  i;

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

t_cost calc_cost(t_data *data, t_node *current)
{
    t_cost cost;
    size_t stack_a_size;
    size_t min_sorted_index_at_stack_a;
    size_t min_pos;
    size_t max_sorted_index_at_stack_a;
    
    cost.ra = 0;
    cost.rra=0;
    stack_a_size = 0;
    min_sorted_index_at_stack_a = 0;
    min_pos = 0;
    max_sorted_index_at_stack_a = 0;
    
    stack_a_size = ft_stack_size(data->stack_a);
    if (stack_a_size < 2)
        return (cost);
    
    min_sorted_index_at_stack_a = find_min_sorted_index(&(data->stack_a));
    max_sorted_index_at_stack_a = find_max_sorted_index(&(data->stack_a));
    /*
    printf("%zu\n", min_sorted_index_at_stack_a);
    printf("%zu\n", max_sorted_index_at_stack_a);
    printf("%zu\n", current->sorted_index);
    */
    if (current->sorted_index < min_sorted_index_at_stack_a || current->sorted_index > max_sorted_index_at_stack_a)
    {
        min_pos = find_min_pos(&(data->stack_a), min_sorted_index_at_stack_a);
        if (min_pos < stack_a_size / 2)
            cost.ra = min_pos;
        else
            cost.rra = stack_a_size - min_pos;
    }
    else
    {
        size_t  next_sorted_index_pos = 0;

        next_sorted_index_pos = find_next_sorted_index_pos(&(data->stack_a), current->sorted_index);
        //printf("%zu\n", next_sorted_index_pos);
        //printf("%zu\n", stack_a_size);
        if (next_sorted_index_pos < stack_a_size / 2)
            cost.ra = next_sorted_index_pos;
        else
            cost.rra = stack_a_size - next_sorted_index_pos;
    }
    return (cost);
}

/*
void push_back(t_data *data, t_node **stack_b)
{
    t_node *current;
    
    current = *stack_b;
    while (current != NULL)
    {
        t_cost *cost;
        cost = NULL;
        cost = calc_cost(data, current);
        push_back_pa(data, cost);
        current=*stack_b;
    }
}
*/

void push_back(t_data *data, t_node **stack_b)
{
    t_node *current;
    t_cost cost;
    
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

void    quick_sort(t_data *data, size_t index_1)
{
    t_node *current;
    size_t i;
    size_t  stack_a_len;
    
    
    stack_a_len = ft_stack_size(data->stack_a);
    i =0;
    current = data->stack_a;
    while (i <stack_a_len)
    {
        if (current->sorted_index >= index_1)
        {
            operation_pb(data);
        }
        else
            operation_ra(data);
        current = data->stack_a;
        i++;
    }
}

void sort_7_or_more(t_data *data)
{  
    quick_sort(data, data->index_nineth);
    quick_sort(data, data->index_eigth);
    quick_sort(data, data->index_seventh);
    quick_sort(data, data->index_sixth);
    quick_sort(data, data->index_fifth);
    quick_sort(data, data->index_forth);
    quick_sort(data, data->index_third);
    quick_sort(data, data->index_second);
    quick_sort(data, data->index_first);
    quick_sort(data, 0);
    push_back(data, &(data->stack_b));
    
    size_t min_pos;

    min_pos = find_min_pos(&(data->stack_a), 0);
    
    while (data->stack_a->sorted_index != 0)
    {
            if (min_pos < data->stack_len / 2)
                operation_ra(data);
            else
                operation_rra(data);
    }
}
    
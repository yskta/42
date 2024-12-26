/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_1_ft_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:44:13 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/26 17:11:50 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t ft_stack_size(t_node *stack)
{
    size_t size;
    t_node *head;

    size=1;
    head=stack;
    if (stack==NULL)
        return(0);
    while (stack->next!=head)
    {
        size++;
        stack=stack->next;
    }
    return(size);
}

void ft_stack_last(t_node *stack)
{
    t_node *head;
    t_node *current;

    if (stack == NULL)
        return ;
    head=stack;
    current=stack->next;
    while(current != head)
    {
        if (current == head->prev)
            current->end = true;
        else
            current->end = false;
        current = current->next;
    }
}

void ft_stack_add_front(t_node **stack, t_node *new)
{
    t_node *head;
    t_node *tail;
    
    if(new == NULL || stack == NULL)
        return ;
    if (*stack == NULL)
    {
        *stack=new;
        new->prev=new;
        new->next=new;
        new->end=true;
        return ;
    }
    head = *stack;
    tail = head->prev;
    new->prev = tail;
    new->next = head;
    tail->next=new;
    head->prev=new;
    *stack=new;
}

size_t find_min_sorted_index(t_node **stack)
{
    size_t min_sorted_index;
    t_node *current;

    current = *stack;
    min_sorted_index = current->sorted_index;
    while (current->end == false)
    {
        if (min_sorted_index > current->sorted_index)
            min_sorted_index = current->sorted_index;
        current = current->next;
    }
    if (min_sorted_index > current->sorted_index)
            min_sorted_index = current->sorted_index;
    return (min_sorted_index);
}

size_t find_min_pos(t_node **stack, size_t index)
{
    size_t  min_pos;
    t_node  *current;

    min_pos = 0;
    current = *stack;
    while (current->sorted_index != index)
    {
        min_pos++;
        current = current->next;
    }   
    return (min_pos);
}

size_t find_max_sorted_index(t_node **stack)
{
    size_t max_sorted_index;
    t_node *current;

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

size_t find_next_sorted_index_pos(t_node **stack, size_t index)
{
    t_node *current;
    size_t prev_sorted_index;
    size_t next_sorted_index;
    size_t next_sorted_index_pos;

    current = *stack;
    prev_sorted_index = current->prev->sorted_index;
    next_sorted_index = current->sorted_index;
    next_sorted_index_pos = 0;
    while (current->end == false)
    {
        prev_sorted_index = current->prev->sorted_index;
        next_sorted_index = current->sorted_index;
        if (prev_sorted_index < index &&  index < next_sorted_index)
            break;
        next_sorted_index_pos++;
        current=current->next;
    }
    return (next_sorted_index_pos);
}

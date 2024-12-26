/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:44:13 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/20 14:34:04 by yokitaga         ###   ########.fr       */
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
    while(current->next != head)
    {
        if (current->next == head->prev)
            current->next->end = true;
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
    if ((*stack)->next == *stack)
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

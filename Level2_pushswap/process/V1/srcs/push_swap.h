/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 23:30:31 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/20 13:48:10 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//printf 使う用
# include <stdio.h>
//malloc
#include <stdlib.h>

#include <stdbool.h>

//双方向循環連結リスト

typedef struct s_node{
    struct s_node  *prev;
    int             value;
    struct s_node  *next;
    bool           end;
      
}t_node;

typedef struct s_data{
    t_node *stack_a;
    t_node *stack_b;

    
    size_t stack_len;
}t_data;

t_node  *create_stack_b();
t_node  *create_node(int value);
t_node  *create_stack(int data[],int n);

size_t  ft_stack_size(t_node *stack);
void    ft_stack_last(t_node *stack);
void    ft_stack_add_front(t_node **stack, t_node *new);

void    sa_or_sb(t_node **stack_head);
void    operation_sa(t_data *data);
void    operation_sb(t_data *data);

void    ra_or_rb(t_node **stack_head);
void    operation_ra(t_data *data);
void    operation_rb(t_data *data);

void    rra_or_rrb(t_node **stack_head);
void    operation_rra(t_data *data);
void    operation_rrb(t_data *data);

t_node  *pop(t_node **stack_head);
void    operation_pa(t_data *data);
void    operation_pb(t_data *data);

#endif
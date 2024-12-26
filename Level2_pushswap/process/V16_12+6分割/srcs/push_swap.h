/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 23:30:31 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/25 17:33:33 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//gcc -fsanitize=address -g srcs/*.c lib/*.c

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//libraryを使う用
# include "../lib/libft.h"
//printf 使う用
# include <stdio.h>
//malloc
#include <stdlib.h>

#include <stdbool.h>

//双方向循環連結リスト
typedef struct s_node{
    struct s_node  *prev;
    int            value;
    struct s_node  *next;
    bool           end;
    size_t         sorted_index; //座標圧縮用//最初は引数順。valueに合わせて入れ替える。
}t_node;

typedef struct s_data{
    t_node  *stack_a;
    t_node  *stack_b;
    int     *sorted_array;
    size_t  count;
    size_t  stack_len;
    size_t  index_min;
    /*
    size_t  index_first_quater;
    size_t  index_second_quater;
    size_t  index_third_quater;
    */

    size_t  index_first;
    size_t  index_second;
    size_t  index_third;
    size_t  index_forth;
    size_t  index_fifth;
    size_t  index_sixth;
    size_t  index_seventh;
    size_t  index_eigth;
    size_t  index_nineth;
    size_t  index_tenth;
    size_t  index_eleventh;
    size_t  index_max;
}t_data;

typedef struct s_cost{
    size_t  ra;
    size_t  rra;
}t_cost;

int     *set_array(int argc, char *argv[]); 

t_data  *init_data(int *array);
int     *sort_array(int array[]);
t_node  *create_node(int value, size_t index);
t_node  *create_stack(int array[]);
void    set_sorted_index(t_data *data);

size_t  ft_stack_size(t_node *stack);
void    ft_stack_last(t_node *stack);
void    ft_stack_add_front(t_node **stack, t_node *new);
size_t  find_min_sorted_index(t_node **stack);
size_t  find_min_pos(t_node **stack, size_t index);
size_t  find_max_sorted_index(t_node **stack);
size_t  find_next_sorted_index_pos(t_node **stack, size_t index);

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

bool    confirm_sorted(t_node **stack);

void    sort_3_or_less(t_data *data, t_node *stack);
void    sort_4(t_data *data);
void    sort_5(t_data *data);
void    sort_6(t_data *data);

//void    quick_sort(t_data *data, size_t index_1, size_t index_2);
void    push_back_pa(t_data *data, t_cost *cost);
t_cost  calc_cost(t_data *data, t_node *current);
void    push_back(t_data *data, t_node **stack_b);

void    quick_sort(t_data *data, size_t index_1);
void    sort_7_or_more(t_data *data);

//void    free_data(t_data *data);

#endif
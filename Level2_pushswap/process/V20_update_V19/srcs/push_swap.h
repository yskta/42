/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 23:30:31 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/27 00:19:47 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//gcc -fsanitize=address -g srcs/*.c lib/*.c

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft.h"
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct s_node{
    struct s_node  *prev;
    int            value;
    struct s_node  *next;
    bool           end;
    size_t         sorted_index;
}t_node;

typedef struct s_data{
    bool    comp_prep_stack_a;
    bool    stack_malloc;
    t_node  *stack_a;
    t_node  *stack_b;
    int     *sorted_array;
    int     n_data;
    int     stack_len;
    size_t  index_min;

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

int	    ft_isspace(int c);
bool    check_str(const char *str);
int     n_atoi(const char *str, int flag);
int	    ft_atoi_for_push_swap(const char    *str);
int     *set_array(int argc, char *argv[]); 

t_data  *init_data(int *array, int argc);
int     *sort_array(int array[], int size);
t_node  *create_node(int value, size_t index);
t_node  *create_stack(int array[], int size);
void    set_sorted_index(t_data *data);
bool    check_duplicate(int *array);
size_t  get_array_size(int *array);

int     ft_stack_size(t_node *stack);
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

void    push_back_pa(t_data *data, t_cost *cost);
t_cost  calc_cost(t_data *data, t_node *current);
void    push_back(t_data *data, t_node **stack_b);

void    quick_sort(t_data *data, size_t index_1);
void    sort_7_or_more(t_data *data);

void    free_stack_and_data(t_data *data);

void    put_error_and_exit(void);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_init_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:42:59 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/27 00:19:56 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data *init_data(int array[], int argc)
{
    t_data *data;
    
    data=(t_data *)malloc(sizeof(t_data));
    if (data == NULL)
        return (NULL);
    data->n_data = argc - 1;
    data->stack_malloc = false;
    data->stack_a=create_stack(array, data->n_data);
    if (data->stack_a == NULL)
        return (data);
    data->stack_malloc = true;
    data->stack_b=NULL;
    data->sorted_array = sort_array(array, data->n_data);
    
    data->stack_len=ft_stack_size(data->stack_a);
    
    ft_stack_last(data->stack_a);

    data->comp_prep_stack_a = true;
    if (data->stack_len != data->n_data)
        data->comp_prep_stack_a = false;
    
    set_sorted_index(data);
    data->index_min = 0;
    data->index_max = data->stack_len - 1;
    
    data->index_first = data->index_max / 12;
    data->index_second = data->index_max / 12 * 2;
    data->index_third = data->index_max / 12 * 3;
    data->index_forth = data->index_max / 12 * 4;
    data->index_fifth = data->index_max / 12 * 5;
    data->index_sixth = data->index_max / 12 * 6;
    data->index_seventh = data->index_max / 12 * 7;
    data->index_eigth = data->index_max / 12 * 8;
    data->index_nineth = data->index_max / 12 * 9;
    data->index_tenth = data->index_max / 12 * 10;
    data->index_eleventh = data->index_max / 12 * 11;
    return (data);
}

t_node *create_node(int value, size_t index)
{
    t_node *new_node;

    new_node=(t_node *)malloc(sizeof(t_node));
    if (new_node == NULL)
        return (NULL);
    new_node->value=value;
    new_node->prev=NULL;
    new_node->next=NULL;
    new_node->sorted_index=index;
    return(new_node);
}

t_node *create_stack(int array[], int size)
{
    t_node *head;
    t_node *tail;
    int i;

    i=1;
    head=create_node(array[0], 0);
    if (head == NULL)
        return (NULL);
    tail=head;
    while(i < size)
    {
        t_node *new_node;
        new_node=create_node(array[i], i);
        if (new_node == NULL)
        {
            head->prev=tail;
            tail->next=head;
            return (head);
        }
        tail->next=new_node;
        new_node->prev=tail;
        tail=new_node;
        i++;
    }
    head->prev=tail;
    tail->next=head;
    return (head);
}

int *sort_array(int *array, int size)
{
    int     *sorted_array;
    size_t  i;
    size_t  j;
    int     tmp;
    
    sorted_array = array;
    i = 0;
    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if (sorted_array[i] > sorted_array[j])
            {
                tmp = sorted_array[i];
                sorted_array[i] = sorted_array[j];
                sorted_array[j] = tmp;
            }
            j++;
        }
        i++;
    }
    return (sorted_array);
}

void set_sorted_index(t_data *data)
{
    size_t  index;
    t_node  *current;
    
    index = 0;
    current = data->stack_a;
    while (current->end == false)
    {
        index = 0;
        while (index < data->n_data)
        {
            if (current->value == data->sorted_array[index])
            {
                current->sorted_index = index;
                break;
            }
            index++;
        }
        current = current->next;   
    }
    index = 0;
    while (index < data->n_data)
    {
        if (current->value == data->sorted_array[index])
        {
            current->sorted_index = index;
            break;
        }
        index++;
    }
}

bool    check_duplicate(int *array)
{
    bool    check_result;
    size_t  i;

    check_result = false;
    i = 0;
    while (array[i + 1] != '\0')
    {
        if (array[i] == array[i + 1])
        {
            check_result = true;
            break;
        }
        i++;
    }
    return(check_result);
}
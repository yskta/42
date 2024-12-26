/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_init_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:42:59 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/23 17:51:13 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data *init_data(int array[])
{
    t_data *data;
    
    data=(t_data *)malloc(sizeof(t_data));
    if (data == NULL)//既にmallocしたもの解放する処理必要だろうけどまだ何もしてない
    {
        ft_printf("MALLOC ERROR AT INIT DATA\n");
        return (NULL);
    }
    data->stack_a=create_stack(array);
    data->stack_b=NULL;
    data->sorted_array = sort_array(array);
    data->count = 0;
    data->stack_len=ft_stack_size(data->stack_a);
    ft_stack_last(data->stack_a);
    set_sorted_index(data);
    data->index_min = 0; 
    data->index_max = data->stack_len - 1;
    data->index_median = (data->index_max / 2) + 1;
    //printf ("index min: %zu\n", data->index_min);
    //printf ("index min: %zu\n", data->index_median);
    //printf ("index min: %zu\n", data->index_max);
    return (data);
}

t_node *create_node(int value, size_t index)
{
    t_node *new_node;

    new_node=(t_node *)malloc(sizeof(t_node));
    new_node->value=value;
    new_node->prev=NULL;
    new_node->next=NULL;
    new_node->sorted_index=index;
    return(new_node);
}
//双方向循環リスト作成

t_node *create_stack(int array[])
{
    t_node *head;
    t_node *tail;
    int i;

    i=1;
    head=create_node(array[0], 0);
    tail=head;
    while(array[i] != '\0')
    {
        t_node *new_node;
        new_node=create_node(array[i], i);
        tail->next=new_node;
        new_node->prev=tail;
        tail=new_node;
        i++;
    }
    head->prev=tail;
    tail->next=head;
    return(head);
}

int *sort_array(int array[])
{
    size_t  i;
    size_t  j;
    int     tmp;

    i = 0;
    while (array[i] != '\0')
    {
        j = i + 1;
        while (array[j] != '\0')
        {
            if (array[i] > array[j])
            {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
            j++;
        }
        i++;
    }
    return (array);
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
        while (data->sorted_array[index] != '\0')
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
    while (data->sorted_array[index] != '\0')
    {
        if (current->value == data->sorted_array[index])
        {
            current->sorted_index = index;
            break;
        }
        index++;
    }
}
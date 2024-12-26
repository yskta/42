/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:10:10 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/25 02:31:10 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//malloc or callocしたものメモ(後でfreeしないといけない)
//
int main(int argc, char *argv[])
{
    t_data *data;
    int    *array;
    
    if (argc - 1 <= 0)
        return (0);
    
    array = set_array(argc, argv);
    data = init_data(array);

    free(array);
    
    t_node *current_node;
    t_node *current_node_b;
    
    current_node=data->stack_a;
    
    printf("---before swap---\n");
    printf("[stack a]\n");
    do{
        printf("value:%d/", current_node->value);
        printf("end:%d/", current_node->end);
        printf("index:%zu\n", current_node->sorted_index);
        current_node=current_node->next;
    }while(current_node != data->stack_a);
    
    if (confirm_sorted(&(data->stack_a)) == true)
        return (0);
    if (data->stack_len < 4)
        sort_3_or_less(data, data->stack_a);
    else if (data->stack_len == 4)
        sort_4(data);
    else if (data->stack_len == 5)
        sort_5(data);
    else if (data->stack_len == 6)
        sort_6(data);
    else
        sort_7_or_more(data);
    
    printf("---after swap---\n");
    
    printf("[stack a]\n");
    current_node=data->stack_a;
    do{
        printf("value:%d/", current_node->value);
        printf("end:%d/", current_node->end);
        printf("index:%zu\n", current_node->sorted_index);
        current_node=current_node->next;
    }while(current_node != data->stack_a);
    
    printf("[stack b]\n");
    current_node_b = data->stack_b;
    
    do{
        printf("value:%d/", current_node_b->value);
        printf("end:%d/", current_node_b->end);
        printf("index:%zu\n", current_node_b->sorted_index);
        current_node_b=current_node_b->next;
    }while(current_node_b != data->stack_b);
    
    printf("%zu\n", data->count);
    
    //free_data(data);
    return (0);
}
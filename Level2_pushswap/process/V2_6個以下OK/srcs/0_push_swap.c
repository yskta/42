/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:10:10 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/23 17:19:18 by yokitaga         ###   ########.fr       */
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
    
    printf("---before swap---\n");
    
    current_node=data->stack_a;
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
    //else
        //sort_7_or_more(data);
    printf("---after swap---\n");
    
    current_node=data->stack_a;
    do{
        printf("value:%d/", current_node->value);
        printf("end:%d/", current_node->end);
        printf("index:%zu\n", current_node->sorted_index);
        current_node=current_node->next;
    }while(current_node != data->stack_a);
    printf("%zu\n", data->count);
    //free_data(data);
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:10:10 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/26 19:50:29 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
    t_data *data;
    int    *array;
    
    if (argc < 2)
        return (0);
    
    array = set_array(argc, argv);
    if (array == NULL)
        put_error_and_exit();
    
    size_t  array_size;
    array_size = get_array_size(array);
    if (array_size != argc - 1)
    {
        free(array);
        put_error_and_exit();
    }

    data = init_data(array);
    
    if (data == NULL)
        put_error_and_exit();
    
    if (data->stack_malloc == false)
    {
        free(array);
        free_stack_and_data(data);
        put_error_and_exit();
    }

    if (data->comp_prep_stack_a == false)
    {
        free(array);
        free_stack_and_data(data);
        put_error_and_exit();
    }
    
    if (check_duplicate(array) == true)
    {
        free(array);
        free_stack_and_data(data);
        put_error_and_exit();
    }
    
    if (confirm_sorted(&(data->stack_a)) == true)
    {
        free(array);
        free_stack_and_data(data);
        return (0);
    }

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

    free(array);
    free_stack_and_data(data);
    return (0);
}
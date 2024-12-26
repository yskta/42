/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:10:10 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/27 04:53:05 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_data	*data;
	int		*array;

	if (argc < 2)
		return (0);
	array = set_array(argc, argv);
	error_handle_after_set_array(array, argc);
	data = init_data(array, argc);
	error_handle_after_init_data(data, array);
	if (confirm_sorted(&(data->stack_a)) == true)
	{
		free(array);
		free_stack_and_data(data);
		return (0);
	}
	sort(data);
	free(array);
	free_stack_and_data(data);
	return (0);
}

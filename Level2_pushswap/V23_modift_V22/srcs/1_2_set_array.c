/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_2_set_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 02:28:10 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/27 02:45:42 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handle_after_set_array(int *array, int argc)
{
	if (array == NULL)
		put_error_and_exit();
	if (argc == 2)
	{
		free(array);
		exit(EXIT_SUCCESS);
	}
}

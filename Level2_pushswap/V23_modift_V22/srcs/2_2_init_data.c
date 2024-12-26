/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_2_init_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 01:25:37 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/27 15:35:55 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_array(int *array, size_t size)
{
	int		*sorted_array;
	size_t	i;
	size_t	j;
	int		tmp;

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

void	set_sorted_index(t_data *data)
{
	size_t	index;
	size_t	cnt;
	t_node	*current;

	cnt = 0;
	index = 0;
	current = data->stack_a;
	while (cnt != data->n_data)
	{
		index = 0;
		while (index < data->n_data)
		{
			if (current->value == data->sorted_array[index])
			{
				current->sorted_index = index;
				break ;
			}
			index++;
		}
		current = current->next;
		cnt++;
	}
}

void	init_data_index(t_data *data)
{
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
}

bool	check_duplicate(int *array)
{
	bool	check_result;
	size_t	i;

	check_result = false;
	i = 0;
	while (array[i + 1] != '\0')
	{
		if (array[i] == array[i + 1])
		{
			check_result = true;
			break ;
		}
		i++;
	}
	return (check_result);
}

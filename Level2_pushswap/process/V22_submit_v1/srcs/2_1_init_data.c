/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_1_init_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:42:59 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/27 14:58:16 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handle_after_init_data(t_data *data, int *array)
{
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
}

t_data	*init_data(int array[], int argc)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data->n_data = (size_t)argc - 1;
	data->stack_malloc = false;
	data->stack_a = create_stack(array, data->n_data);
	if (data->stack_a == NULL)
		return (data);
	data->stack_malloc = true;
	data->stack_b = NULL;
	data->sorted_array = sort_array(array, data->n_data);
	data->stack_len = ft_stack_size(data->stack_a);
	ft_stack_last(data->stack_a);
	data->comp_prep_stack_a = true;
	if (data->stack_len != data->n_data)
		data->comp_prep_stack_a = false;
	set_sorted_index(data);
	init_data_index(data);
	return (data);
}

t_node	*create_node(int value, size_t index)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->value = value;
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->sorted_index = index;
	return (new_node);
}

void	operation_head_tail(t_node *head, t_node *tail)
{
	head->prev = tail;
	tail->next = head;
}

t_node	*create_stack(int array[], int size)
{
	t_node	*head;
	t_node	*tail;
	t_node	*new_node;
	int		i;

	i = 1;
	head = create_node(array[0], 0);
	if (head == NULL)
		return (NULL);
	tail = head;
	while (i < size)
	{
		new_node = create_node(array[i], i);
		if (new_node == NULL)
		{
			operation_head_tail(head, tail);
			return (head);
		}
		tail->next = new_node;
		new_node->prev = tail;
		tail = new_node;
		i++;
	}
	operation_head_tail(head, tail);
	return (head);
}

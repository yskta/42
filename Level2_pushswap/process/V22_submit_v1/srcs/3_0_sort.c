/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_0_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 02:30:04 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/27 02:47:13 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_data *data)
{
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
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_1_set_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:34:53 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/28 10:55:32 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(int c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

bool	check_str(const char *str)
{
	bool	check_result;
	size_t	i;

	check_result = true;
	i = 0;
	if (ft_isdigit(str[i]) == 0)
	{
		check_result = false;
		return (check_result);
	}
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0 && ft_isspace(str[i]) == 0)
		{
			check_result = false;
			break ;
		}
		i++;
	}
	return (check_result);
}

int	n_atoi(const char *str, int flag)
{
	long long int	n;

	n = 0;
	while (ft_isdigit(*str) == 1)
	{
		n = n * 10 + (*str - '0');
		if (n < INT_MIN || INT_MAX < n)
			put_error_and_exit();
		str++;
	}
	if (flag == -1)
		n *= -1;
	return ((int)n);
}

int	ft_atoi_for_push_swap(const char	*str)
{
	int	n;
	int	flag;

	if (*str == '\0')
		put_error_and_exit();
	n = 0;
	flag = 1;
	while (*str != '\0' && ft_isspace(*str) == 1)
		str++;
	if (*str == '-')
	{
		flag = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if (check_str(str) == false)
		put_error_and_exit();
	n = n_atoi(str, flag);
	return (n);
}

int	*set_array(int argc, char *argv[])
{
	int		*array;
	int		i;

	array = (int *)ft_calloc(argc, sizeof(int));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		array[i] = ft_atoi_for_push_swap(argv[i + 1]);
		i++;
	}
	return (array);
}

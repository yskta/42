/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_set_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:34:53 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/26 23:31:42 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	ft_isspace(int c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

const char	*ft_skipspace(const char *str)
{
	while (ft_isspace(*str) == 1)
		str++;
	return (str);
}

const char	*ft_flag(const char *str, int *sign)
{
	*sign = 1;
	if (*str == '-')
	{
		*sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	return (str);
}

int	ft_atoi(const char	*str)
{
	size_t			n;
	int				flag;
	size_t			ov_dev;
	int				ov_mod;

	n = 0;
	str = ft_flag(ft_skipspace(str), &flag);
	ov_dev = LONG_MAX;
	ov_mod = ov_dev % 10;
	ov_dev = ov_dev / 10;
	while (ft_isdigit(*str) == 1)
	{
		if (n > ov_dev || (n == ov_dev && (*str - '0') > ov_mod))
		{
			if (flag == 1)
				return ((int)LONG_MAX);
			else
				return ((int)LONG_MIN);
		}
		n = n * 10 + (*str++ - '0');
	}
	if (flag == -1)
		n *= -1;
	return ((int)n);
}

bool  check_argv(char *argv)
{
    bool check_result;

    check_result = true;
    while (*argv != '\0')
    {
        if (ft_isdigit(*argv) == 0 && )
        {
            check_result = false;
            break;
        }
        argv++;
    }
    return (check_result);
}

int *set_array(int argc, char *argv[])
{
    int *array;
    size_t  i;
    
    array = (int *)ft_calloc(argc, sizeof(int));
    if (array == NULL)
        return (NULL);
    i = 0;
    while (i < argc - 1)
    {
        if (check_argv(argv[i + 1]) == false)
            return (array);
        array[i] =  ft_atoi(argv[i + 1]);
        i++;
    }
    return (array);
}
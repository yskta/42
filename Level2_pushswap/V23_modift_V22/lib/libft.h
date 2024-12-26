/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:38:52 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/27 23:15:58 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "stdarg.h"
# include <stddef.h>
# include <stdio.h>


int				ft_isdigit(int c);
size_t			ft_strlen(const char *str);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t number, size_t size);
char			*ft_itoa(int n);
char			*ft_strdup(const char *src);
size_t	        ft_strlcpy(char *dest, const char *src, size_t n);

int				ucntdigit(unsigned int n);
void			convert_uint_to_char(unsigned int n, char *num, int n_digit);
char			*ft_unsigneditoa(unsigned int n);
unsigned int	ft_hex_len(unsigned int u);
char			*ft_showhex(unsigned int u, int fmt);
char			*ft_showhex_forull(unsigned long long pointer);
unsigned int	ft_hex_plen(unsigned long long pointer);
int				ft_count_and_putchar(char c);
int				ft_count_and_putstr(char *s);
int				ft_count_and_putint(int i);
int				ft_cntputunsigned(unsigned int u);
int				ft_cntputhexa(unsigned int u, int fmt);
int				ft_cntputpointer(unsigned long long pointer);
int				ft_judge_and_output(va_list ap, int fmt);
int				ft_count(va_list ap, const char *fmt);
int				ft_printf(const char *fmt, ...);

#endif

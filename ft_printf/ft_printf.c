/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:37:13 by donghyk2          #+#    #+#             */
/*   Updated: 2022/11/04 01:46:49 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_ret_cnt(const char *s, va_list ap)
{
	int	cnt;
	int	flag;

	cnt = 0;
	flag = 0;
	while (*s)
	{
		if (*s != '%' && !flag)
		{
			write (1, s, 1);
			cnt++;
		}
		else if (*s == '%')
			flag = 1;
		else if (flag)
		{
			flag = 0;
			va_arg(ap, type);
		}
		s++;
	}
	return (cnt);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		cnt;

	cnt = 0;
	va_start(ap, s);
	cnt == print_ret_cnt(s, ap);
	va_end(ap);
	return (cnt);
}

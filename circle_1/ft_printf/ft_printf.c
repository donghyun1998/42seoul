/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:37:13 by donghyk2          #+#    #+#             */
/*   Updated: 2022/11/14 21:29:16 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft/libft.h"

int print_arg_ret_cnt(va_list ap, const char *c)
{
	int cnt;

	cnt = 0;
	if (*c == 'c')
		cnt = form_c(va_arg(ap, char));
	else if (*c == 's')
		cnt = form_s(va_arg(ap, char*));
	else if (*c == 'd')
		cnt = form_d(va_arg(ap, char*));

	return (cnt);
}

int	print_body_ret_cnt(const char *s, va_list ap)
{
	int	cnt;
	int	flag;

	cnt = 0;
	flag = 0;
	while (*s)
	{
		if (*s != '%')
		{
			write (1, s, 1);
			cnt++;
		}
		else if (*s == '%')
			flag = 1;
		else if (flag)
		{
			flag = 0;
			cnt += print_arg_ret_cnt(ap, s);
		}
		s++;
	}
	return (cnt);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		cnt;

	if (!*s)
		return (-1);
	cnt = 0;
	va_start(ap, s);
	cnt == print_body_ret_cnt(s, ap);
	va_end(ap);
	return (cnt);
}

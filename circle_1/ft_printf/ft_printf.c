/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:37:13 by donghyk2          #+#    #+#             */
/*   Updated: 2022/11/22 16:42:00 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_va_arg(va_list *ap, const char form)
{
	if (form == 'c')
		return (form_c(va_arg(*ap, int)));
	else if (form == 's')
		return (form_s(va_arg(*ap, char *)));
	else if (form == 'p')
		return (form_p(va_arg(*ap, long long)));
	else if (form == 'd' || form == 'i')
		return (form_diu(va_arg(*ap, int)));
	else if (form == 'u')
		return (form_diu(va_arg(*ap, unsigned int)));
	else if (form == 'x')
		return (form_x(va_arg(*ap, unsigned int), 1));
	else if (form == 'X')
		return (form_x(va_arg(*ap, unsigned int), 0));
	else if (form == '%')
		return (form_c('%'));
	return (-1);
}

int	print_ret_cnt(va_list *ap, const char *s)
{
	int	cnt;
	int	check;

	cnt = 0;
	while (*s)
	{
		check = 0;
		if (*s != '%')
			check = write(1, s, 1);
		else if (++s)
			check = print_va_arg(ap, *s);
		if (check < 0)
			return (-1);
		cnt += check;
		s++;
	}
	return (cnt);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		cnt;

	va_start(ap, s);
	cnt = print_ret_cnt(&ap, s);
	va_end(ap);
	return (cnt);
}

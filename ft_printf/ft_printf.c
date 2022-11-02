/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:37:13 by donghyk2          #+#    #+#             */
/*   Updated: 2022/11/02 17:10:45 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_ret_cnt(const char *s)
{
	int	cnt;
	int	flag;

	cnt = 0;
	flag = 0;
	while (*s)
	{
		if (s)
		
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
	cnt == print_ret_cnt(s);
	return (cnt);
}

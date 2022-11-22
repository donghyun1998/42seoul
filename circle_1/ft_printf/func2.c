/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:54:42 by donghyk2          #+#    #+#             */
/*   Updated: 2022/11/22 16:26:16 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(unsigned long long n, int cnt, const char *hexarr)
{
	if (n > 15)
		print_ptr(n / 16, cnt, hexarr);
	if (n)
		cnt += write(1, &hexarr[n % 16], 1);
	else
		cnt -= 1;
	return (cnt);
}

int	ft_print_ptr_ret_cnt(unsigned long long p)
{
	const char	*small = "0123456789abcdef";

	return (print_ptr(p, 0, small));
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

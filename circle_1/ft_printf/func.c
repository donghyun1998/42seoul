/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:24:03 by donghyk2          #+#    #+#             */
/*   Updated: 2022/11/22 16:33:58 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print(long long n, int cnt)
{
	char	left;

	if (n > 9)
		print(n / 10, cnt);
	left = n % 10 + '0';
	cnt += write(1, &left, 1);
	return (cnt);
}

int	ft_putnbr_ret_cnt(long long n, int cnt)
{
	if (n < 0)
	{
		n *= -1;
		cnt += write(1, "-", 1);
		return (print(n, cnt));
	}
	else
		return (print(n, cnt));
}

int	print_hex(long long n, int cnt, const char *hexarr)
{
	if (n < 0)
	{
		n *= -1;
		write (1, "-", 1);
		cnt++;
	}
	if (n > 15)
		print_hex(n / 16, cnt, hexarr);
	cnt += write(1, &hexarr[n % 16], 1);
	return (cnt);
}

int	ft_print_hex_ret_cnt(long long n, int x)
{
	const char	*small = "0123456789abcdef";
	const char	*big = "0123456789ABCDEF";

	if (x)
		return (print_hex(n, 0, small));
	else
		return (print_hex(n, 0, big));
}

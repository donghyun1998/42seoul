/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:24:03 by donghyk2          #+#    #+#             */
/*   Updated: 2022/11/21 20:55:43 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print(long long n, int cnt)
{
	char	left;

	if (n > 9)
		cnt = print(n / 10, cnt);
	left = n % 10 + '0';
	write(1, &left, 1);
	cnt++;
	return (cnt);
}

int	ft_putnbr_ret_cnt(long long n, int cnt)
{
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
		cnt++;
		return (print(n, cnt));
	}
	else
		return (print(n, cnt));
}

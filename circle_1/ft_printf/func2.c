/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:54:42 by donghyk2          #+#    #+#             */
/*   Updated: 2022/11/22 17:32:30 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(unsigned long long n, int cnt, const char *hexarr)
{
	int	ret;

	ret = cnt;
	if (n > 15)
		ret = print_ptr(n / 16, cnt, hexarr);
	if (n)
		ret += write(1, &hexarr[n % 16], 1);
	else
		ret -= 1;
	return (ret);
}

int	ft_print_ptr_ret_cnt(unsigned long long p)
{
	const char	*small = "0123456789abcdef";

	if (!p)
		return (write(1, "0", 1));
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

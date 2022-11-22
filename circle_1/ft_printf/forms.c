/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:56:18 by donghyk2          #+#    #+#             */
/*   Updated: 2022/11/22 17:14:04 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	form_c(int c)
{
	return (write (1, &c, 1));
}

int	form_s(char *s)
{
	if (!s)
		return (write (1, "(null)", 6));
	return (write (1, s, ft_strlen(s)));
}

int	form_p(unsigned long long p)
{
	return (write (1, "0x", 2) + ft_print_ptr_ret_cnt(p));
}

int	form_diu(long long c, int u_flag)
{
	if (u_flag)
		return (ft_putnbr_ret_cnt(c, 0));
	else
		return (ft_putnbr_ret_cnt((int)c, 0));
}

int	form_x(long long c, int x)
{
	if (x)
		return (ft_print_hex_ret_cnt(c, 1));
	else
		return (ft_print_hex_ret_cnt(c, 0));
}

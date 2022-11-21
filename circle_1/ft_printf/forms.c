/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:56:18 by donghyk2          #+#    #+#             */
/*   Updated: 2022/11/21 21:05:08 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	form_c(int c)
{
	return (write (1, &c, 1));
}

int	form_s(char *s)
{
	return (write (1, s, ft_strlen(s)));
}

int	form_p()
{
	int	cnt;

	cnt = 2;
	write (1, "0x", 2);
	
}

int	form_diu(int c)
{
	return (ft_putnbr_ret_cnt(c, 0));
}



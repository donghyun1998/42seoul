/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:56:18 by donghyk2          #+#    #+#             */
/*   Updated: 2022/11/14 21:30:17 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft/libft.h"

int	form_c(char c)
{
	write (1, &c, 1);
	return (1);
}

int	form_s(char *s)
{
	int	len;

	len = ft_strlen(s);
	write (1, s, len);
	return (len);
}

int	form_d(char *s)
{
	int	n;

	n = ft_atoi(s);
}

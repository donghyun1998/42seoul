/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:56:18 by donghyk2          #+#    #+#             */
/*   Updated: 2022/11/18 19:51:58 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	form_c(char c)
{
	return (write (1, &c, 1));
}

int	form_s(char *s)
{
	return (write (1, s, ft_strlen(s)));
}

int	form_p()
{

}

int	form_di(char *s)
{
	int	n;

}

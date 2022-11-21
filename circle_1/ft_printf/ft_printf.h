/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:23:59 by donghyk2          #+#    #+#             */
/*   Updated: 2022/11/21 20:52:50 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	print_ret_cnt(va_list ap, const char *s);
int	is_form(const char *s);
int print_va_arg(va_list ap, const char form);
static int	print(long long n, int cnt);
int	ft_putnbr_ret_cnt(long long n, int cnt);

#endif

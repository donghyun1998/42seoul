/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:23:59 by donghyk2          #+#    #+#             */
/*   Updated: 2022/11/24 17:06:50 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
int		print_ret_cnt(va_list *ap, const char *s);
int		print_va_arg(va_list *ap, const char form);
int		print(long long n, int cnt);
int		ft_putnbr_ret_cnt(long long n, int cnt);
int		ft_print_hex_ret_cnt(long long n, int x);
int		print_hex(long long n, int cnt, const char *hexarr);
int		print_ptr(unsigned long long n, int cnt, const char *hexarr);
int		ft_print_ptr_ret_cnt(unsigned long long p);
int		form_c(int c);
int		form_s(char *s);
int		form_p(unsigned long long p);
int		form_diu(long long c, int uflag);
int		form_x(long long c, int x);
size_t	ft_strlen(const char *s);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:42:19 by donghyk2          #+#    #+#             */
/*   Updated: 2022/11/19 20:06:44 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main()
{
	int	a = 41;
	int b = 42;
	int	c = 43;
	t_list	*node2;
	t_list	*node1;
	t_list	*node3;
	t_list	*begin;

	node1 = ft_lstnew(&a);
	node2 = ft_lstnew(&b);
	ft_lstadd_front(&node2, node1);
	ft_lstadd_back(&node2, ft_lstnew(&c));
	begin = node1;
	while (begin)
	{
		printf ("%d\n", *((int*)begin->content));
		begin = begin->next;
	}
}

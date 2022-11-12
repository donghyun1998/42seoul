/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:03:24 by donghyk2          #+#    #+#             */
/*   Updated: 2022/11/10 17:05:32 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*tmp;
	t_list	*begin;

	res = ft_lstnew(f(lst->content));
	if (!lst || !f || !res)
		return (0);
	begin = res;
	tmp = res;
	while (lst)
	{
		tmp->next = ft_lstnew(f(lst->content));
		if (!tmp->next)
		{
			ft_lstclear(&res, del);
			return (0);
		}
		tmp = tmp->next;
		lst = lst->next;
	}
	res = begin;
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:13:54 by donghyk2          #+#    #+#             */
/*   Updated: 2022/10/28 13:19:56 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**allfree(char **res, int index)
{
	int	i;

	i = -1;
	while (++i < index)
		free(res[i]);
	free(res);
	return (0);
}

static int	biglen(char *s, char c)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			len++;
		while (s[i] != c && s[i])
			i++;
	}
	return (len);
}

static int	smalllen(char *s, char c, int *j)
{
	int	tmp;

	tmp = *j;
	while (s[*j] != c && s[*j])
		(*j)++;
	return (*j - tmp + 1);
}

static void	init(char **res, char *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	if (biglen((char *)s, c) == 0)
	{
		res[j] = 0;
		return ;
	}
	while (s[i])
	{
		k = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
			res[j][k++] = s[i++];
		res[j++][k] = '\0';
		while (s[i] == c && s[i])
			i++;
	}
	res[j] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	if (!s)
		return (0);
	res = (char **)malloc(sizeof(char *) * (biglen((char *)s, c) + 1));
	if (!res)
		return (0);
	i = -1;
	while (++i < biglen((char *)s, c))
	{
		if (biglen((char *)s, c) == 0)
			break ;
		j = 0;
		while (s[j] == c && s[j])
			j++;
		res[i] = (char *)malloc(sizeof(char) * (smalllen((char *)s, c, &j)));
		if (!res[i])
			return (allfree(res, i));
	}
	init(res, (char *)s, c);
	return (res);
}

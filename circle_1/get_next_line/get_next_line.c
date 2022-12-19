/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:27:47 by donghyk2          #+#    #+#             */
/*   Updated: 2022/12/19 22:01:36 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_new_line_index(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*add_line(char *buffer, int fd, int *linelen)
{
	char	*res;
	char	*newbuffer;
	int		readsize;

	newbuffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	readsize = read(fd, newbuffer, BUFFER_SIZE);
	newbuffer[readsize] = '\0';
	res = ft_strjoin(buffer, newbuffer);
	if (find_new_line_index(res) != -1)
		*linelen = find_new_line_index(res) + 1;
	free(buffer);
	buffer = 0;
	free(newbuffer);
	newbuffer = 0;
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buffer;
	char		*line;
	int			linelen;

	linelen = -1;
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!backup)
		backup = ft_strdup("");
	if (find_new_line_index(backup) == -1) // 백업에 개행 없으면
	{
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (0);
		buffer = add_line(buffer, fd, &linelen);
		while (find_new_line_index(buffer) == -1 || linelen % BUFFER_SIZE || linelen != -1)
			buffer = add_line(buffer, fd, &linelen);
	}
	else
	{
		buffer = ft_strdup(backup);
		linelen = find_new_line_index(buffer) + 1;
	}
	line = ft_substr(buffer, 0, linelen);
	backup = ft_substr(buffer, linelen - 1, ft_strlen(buffer) - linelen - 1);
	free(buffer);
	buffer = 0;
	return (line);
}

//경우의 수 다 적어보기

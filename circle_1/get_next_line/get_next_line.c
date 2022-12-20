/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:27:47 by donghyk2          #+#    #+#             */
/*   Updated: 2022/12/20 21:35:40 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	allfree(char *str)
{
	free(str);
	str = 0;
}

int	find_new_line_index(char *buffer)
{
	int	i;

	i = 0;
	if (!buffer)
		return (-1);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

// char	*add_line(char *buffer, int fd, int *readsize)
// {
// 	char	*res;
// 	char	*newbuffer;

// 	newbuffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
// 	*readsize = read(fd, newbuffer, BUFFER_SIZE);
// 	if (*readsize == 0)
// 	{
// 		allfree(newbuffer);
// 		return (buffer);
// 	}
// 	newbuffer[*readsize] = '\0';
// 	res = ft_strjoin(buffer, newbuffer);
// 	allfree(buffer);
// 	allfree(newbuffer);
// 	return (res);
// }

int	add_line(char **buffer, int fd, int *readsize)
{
	char	*res;
	char	*newbuffer;

	newbuffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	*readsize = read(fd, newbuffer, BUFFER_SIZE);
	if (*readsize == 0)
	{
		allfree(newbuffer);
		allfree(*buffer);
		*buffer = NULL;
		return (0);
	}
	newbuffer[*readsize] = '\0';
	res = ft_strjoin(*buffer, newbuffer);
	allfree(*buffer);
	allfree(newbuffer);
	*buffer = res;
	return (1);
}

#include <stdio.h>
char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buffer;
	char		*line;
	int			linelen;
	int			readsize;

	readsize = 1;
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		if (backup)
			allfree(backup);
		return (0);
	}
	if (!backup)
		backup = ft_strdup("");
	buffer = ft_strdup(backup);
	allfree(backup);
	// while (find_new_line_index(buffer) == -1 && readsize) // 백업에 개행 없으면
	// 	buffer = add_line(buffer, fd, &readsize);
	while (add_line(&buffer, fd, &readsize) && find_new_line_index(buffer) == -1)
		;
	if (readsize)
		linelen = find_new_line_index(buffer) + 1;
	else
		linelen = ft_strlen(buffer);
	line = ft_substr(buffer, 0, linelen);
	backup = ft_substr(buffer, linelen, ft_strlen(buffer) - linelen);
	allfree(buffer);
	return (line);
}

//경우의 수 다 적어보기
// #include <stdio.h>
// #include <fcntl.h>
// int main()
// {
// 	int fd;
// 	char *s;

// 	fd = open("ex.txt", O_RDONLY);
// 	s = get_next_line(fd);
// 	while (*s)
// 	{
// 		printf("%s", s);
// 		s = get_next_line(fd);
// 	}
// 	close(fd);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:24:59 by yaekim            #+#    #+#             */
/*   Updated: 2023/12/22 19:42:49 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	update_str(char **str, size_t size)
{
	char	*temp;

	if (*((*str) + size))
	{
		temp = *str;
		*str = ft_strdup((*str) + size);
		free(temp);
		if (!*str)
			return (1);
	}
	else
	{
		free(*str);
		*str = NULL;
	}
	return (0);
}

static char	*get_line(char **str)
{
	char		*line;
	size_t		size;

	if (!*str)
		return (NULL);
	size = check_line(*str);
	line = (char *)malloc(sizeof(char) * size + 1);
	if (!line)
	{
		free(*str);
		*str = NULL;
		return (NULL);
	}
	ft_strlcpy(line, *str, size + 1);
	if (update_str(str, size) == 1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

void	join_str(char **str, char *buff)
{
	char	*temp;

	if (!*str)
	{
		*str = ft_strdup(buff);
		return ;
	}
	temp = *str;
	*str = ft_strjoin(*str, buff);
	free(temp);
}

char	*last_line(char **str)
{
	char	*line;

	if (!*str)
		return (NULL);
	line = ft_strdup(*str);
	if (!line)
	{
		free(*str);
		*str = NULL;
		return (NULL);
	}
	free(*str);
	*str = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		buff[BUFFER_SIZE + 1];
	int			byte;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (check_line(str) > 0)
			return (get_line(&str));
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte == -1)
		{
			free(str);
			str = NULL;
			return (NULL);
		}
		buff[byte] = '\0';
		if (byte == 0)
			return (last_line(&str));
		join_str(&str, buff);
		if (!str)
			return (NULL);
	}
}

// #include <fcntl.h>
// #include <string.h>
// void f1()
// {
// 	system("leaks a.out");
// }

// int main()
// {
// 	// atexit(f1);

// 	int fd = open("giant_line_nl.txt",O_RDONLY);
// 	char *line;

// 	// system("leaks a.out");
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			return (0);
// 		printf("리턴 %s",line);
// 		free(line);

// 	}
// 	return (0);
// }
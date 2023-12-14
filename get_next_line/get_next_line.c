/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:24:59 by yaekim            #+#    #+#             */
/*   Updated: 2023/12/14 22:29:55 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_line(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (-1);
	while (*str)
	{
		count++;
		if (*str == '\n')
			return (count);
		str++;
	}
	return (-1);
}

static char	*get_line(char **str, int size)
{
	char	*line;
	char	*temp;

	if (!*str)
		return (NULL);
	line = (char *)malloc(sizeof(char) * size + 1);
	if (!line)
	{
		free(*str);
		*str = NULL;
		return (NULL);
	}
	ft_strlcpy(line, *str, size + 1);
	// ft_strlcpy(*str, *str+size, ft_strlen(*str) - size + 1);
	if (*((*str) + size))
	{
		// printf("%s\n",*str);
		// printf("%c\n",*((*str) + size));
		temp = *str;
		*str = ft_strdup((*str) + size);
		free(temp);
		if (!*str)
			return (NULL);
	}
	else
	{
		free(*str);
		*str = NULL;
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
	int			size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		size = check_line(str);
		if (size > 0)
		{
			return (get_line(&str, size));
		}
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte == -1) //read error
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

// int main(int argc, char *argv[])
// {
// 	atexit(f1);

// 	int fd = open("text.txt",O_RDONLY);
// 	char *line;
// 	char buff[10];

// 	system("leaks a.out");
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

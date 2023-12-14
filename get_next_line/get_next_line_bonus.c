/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:24:59 by yaekim            #+#    #+#             */
/*   Updated: 2023/12/11 17:51:20 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		return (NULL);
	ft_strlcpy(line, *str, size + 1);
	if (*((*str) + size))
	{
		temp = *str;
		*str = ft_strdup((*str) + size);
		free(temp);
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

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		buff[BUFFER_SIZE + 1];
	int			byte;
	int			size;

	if (fd < 0 || BUFFER_SIZE <= 0 || OPEN_MAX < fd)
		return (NULL);
	// if (str[fd])
	// {
	// 	size = check_line(str[fd]);
	// 	if (size != -1)
	// 		return (get_line(&str[fd], size));
	// }
	while (1)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte == -1)
		{
			if(str[fd])
			{
				free(str[fd]);
				str[fd] = NULL;
			}
			return (NULL);
		}
		buff[byte] = '\0';
		if (byte)
			join_str(&str[fd], buff);
		size = check_line(str[fd]);
		if (size != -1)
			return (get_line(&str[fd], size));
		if (byte < BUFFER_SIZE)
			return (get_line(&str[fd], ft_strlen(str[fd])));
	}
}

// #include <fcntl.h>

// void f1()
// {
// 	system("leaks a.out");
// }

// int main(int argc, char *argv[])
// {
// 	//atexit(f1);
// 	int fd = open("text.txt",O_RDONLY);

// 	int fd2 = open("text2.txt",O_RDONLY);

// 	char *line;
// 	char buff[10];
	
// 	line = get_next_line(fd);
// 	printf("%s",line);
// 	free(line);
// 	line = get_next_line(fd2);
// 	printf("%s",line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s",line);
// 	free(line);
// 	line = get_next_line(fd2);
// 	printf("%s",line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s",line);
// 	free(line);


	// while (1)
	// {
	// 	line = get_next_line(fd);
	// 	if (!line)
	// 		return (0);
	// 	// printf("%s",line);
	// }

// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:24:59 by yaekim            #+#    #+#             */
/*   Updated: 2023/12/30 22:25:00 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

static char	*get_line(char **str, char *buff)
{
	char		*line;
	size_t		size;

	free(buff);
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

char	*check_return(char **buff, char **str, int byte, int *flag)
{
	*flag = 1;
	if (byte == -1)
	{
		free(*str);
		free(*buff);
		*str = NULL;
		return (NULL);
	}
	(*buff)[byte] = '\0';
	if (byte == 0)
	{
		free(*buff);
		return (last_line(str));
	}
	join_str(str, *buff);
	if (!*str)
	{
		free(*buff);
		return (NULL);
	}
	*flag = 0;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*buff;
	char		*result;
	int			byte;
	int			flag;

	if (fd < 0 || BUFFER_SIZE <= 0 || OPEN_MAX < fd)
		return (NULL);
	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
	{
		free(str[fd]);
		str[fd] = NULL;
		return (NULL);
	}
	while (1)
	{
		if (check_line(str[fd]) > 0)
			return (get_line(&str[fd], buff));
		flag = 0;
		byte = read(fd, buff, BUFFER_SIZE);
		result = check_return(&buff, &str[fd], byte, &flag);
		if (flag == 1)
			return (result);
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

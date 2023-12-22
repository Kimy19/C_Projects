/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:25:23 by yaekim            #+#    #+#             */
/*   Updated: 2023/12/22 19:42:04 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

long long	check_line(char *str)
{
	long long	count;

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

size_t	ft_strlen(char const *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (0);
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

char	*ft_strdup(const char *s1)
{
	unsigned int		len;
	unsigned int		i;
	char				*temp;

	i = 0;
	len = ft_strlen(s1);
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (NULL);
	while (s1[i])
	{
		temp[i] = s1[i];
		i++;
	}
	temp[i] = 0;
	return ((char *)temp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	char	*str;

	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!str)
		return (NULL);
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = 0;
	return (str);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	i = 0;
	src_len = ft_strlen(src);
	while (src[i] != 0 && i + 1 < size)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = 0;
	return (src_len);
}

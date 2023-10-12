/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:05:25 by yaekim            #+#    #+#             */
/*   Updated: 2023/10/11 21:00:18 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

char	*ft_strdup(const char *s1)
{
	unsigned int		len;
	char				*temp;

	len = ft_strlen(s1);
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (0);
	while (*s1)
	{
		*temp = *s1;
		temp++;
		s1++;
	}
	*temp = 0;
	return ((char *)temp);
}

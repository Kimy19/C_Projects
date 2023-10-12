/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:55:46 by yaekim            #+#    #+#             */
/*   Updated: 2023/10/12 18:33:35 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_str(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c && (*(s+1) == c || !*(s + 1)))
			count++;
		s++;
	}
	return (count);
}
void	split_strs(char **res, char const *s, char c)
{
	int			size;
	int			index;
	const char	*start;

	index = 0;
	while (*s)
	{
		size = 0;
		while (*s && *s == c)
			s++;
		start = s;
		while (*s && *s != c)
		{
			s++;
			size++;
		}
		if (size > 0)
		{
			res[index] = (char *)malloc(sizeof(char) * (size + 1));
			if (!res[index])
				return (0);
			ft_strlcpy(res[index++], start, size + 1);
		}
	}	
}
char	**ft_split(char const *s, char c)
{
	int			num_str;
	int			index;
	char		**res;

	index = 0;
	num_str = count_str(s, c);
	res = (char **)malloc(sizeof(char *) * (num_str + 1));
	if (!res)
		return (0);
	res[num_str] = 0;
	split_strs(res, s, c);
	return (res);
}

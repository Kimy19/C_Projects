/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:06:54 by yaekim            #+#    #+#             */
/*   Updated: 2023/10/22 18:07:28 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;
	size_t		len_str;

	i = 0;
	if (!s)
		return (0);
	len_str = ft_strlen(s);
	if (start > len_str)
		return (ft_strdup(""));
	if (len_str - start < len)
		len = len_str - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (i + start < len_str && i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = 0;
	return (str);
}

// #include <stdio.h>
// int main()
// {
// 	char *bullshit;
// 	char *strsub;
// 	char str[] = "abc";
//     printf("%s",ft_substr("tripouille", 0, 42000));
// }
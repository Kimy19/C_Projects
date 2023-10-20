/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:06:54 by yaekim            #+#    #+#             */
/*   Updated: 2023/10/20 23:25:25 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;
	size_t		len_str;

	i = 0;
	len_str = ft_strlen(s);
	if (start > len_str)
		return (ft_strdup(""));
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
//     if (!(strsub = ft_substr(str, 400, 20)))
//         printf("NULL");
//     else
//     {
//         bullshit = (char *)&strsub[30];
//         bullshit = "FULL BULLSHIT";
//         if (strsub)
//             printf("%s",strsub);
//         else
//             printf("rip");
//     }
//     if (str == strsub)
//         printf("\nA new string was not returned");
// }
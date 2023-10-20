/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:28:22 by yaekim            #+#    #+#             */
/*   Updated: 2023/10/20 23:07:33 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	if (!s1 || !set)
		return (0);
	if (!*set)
		return (ft_strdup(s1));
	if (!*s1)
		return (ft_strdup(""));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end != 0 && ft_strchr(set, s1[end]))
		end--;
	if (start > end)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!str)
		return (0);
	ft_strlcpy(str, s1 + start, end - start + 2);
	return (str);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
// 	char *s1 = "";
// 	char *s2 = "";
// 	if (!*s1)
// 		printf("XX");
// 	char *ret = ft_strtrim(s1, " \n\t");
// 	char set[] = "dc";
// 	char *res;

// 	// res = ft_strtrim(s1,set);
// 	// printf("%s",res);
// 	printf("%d",strcmp(ret,s2));
// 	return (0);

// }
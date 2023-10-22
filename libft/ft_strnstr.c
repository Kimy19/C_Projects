/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:33:47 by yaekim            #+#    #+#             */
/*   Updated: 2023/10/22 17:48:39 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_word(const char *str, const char *word, size_t len)
{
	size_t	n;
	size_t	len_word;

	n = 0;
	len_word = ft_strlen(word);
	while (*str && len > 0)
	{
		if (*str == *word)
		{
			n++;
			if (n == len_word)
				return (1);
			str++;
			word++;
			len--;
		}
		else
			return (0);
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		if (check_word(haystack, needle, len))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
// 	char str1[] = "aaabcabcd";
// 	char str2[] = "aabc";
// 	char *s1 = str1;
// 	char *s2 = str2;
// 	int	n = -1;
// 	size_t num = n;
// 	printf("%s\n",ft_strnstr(s1,s2,n));
// 	printf("%s\n",strnstr(s1,s2,-1));
// }

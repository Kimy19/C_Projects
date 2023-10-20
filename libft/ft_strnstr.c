/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:33:47 by yaekim            #+#    #+#             */
/*   Updated: 2023/10/20 22:10:56 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

unsigned int	len_str(char *str)
{
	unsigned int	n;

	n = 0;
	while (str[n] != 0)
	{
		n++;
	}
	return (n);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	n;
	unsigned int	len_needle;

	n = 0;
	len_needle = len_str((char *)needle);
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		if (*haystack == needle[n])
			n++;
		else
		{
			n = 0;
			if (*haystack == needle[n])
				n++;
		}
		if (n == len_needle)
			return ((char *)(haystack + 1 - n));
		haystack++;
		len--;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
// 	char str1[] = "ab cd";
// 	char str2[] = "cd";
// 	char *s1 = str1;
// 	char *s2 = str2;
// 	int	n = -1;
// 	printf("%s\n",ft_strnstr(s1,s2,n));
// 	printf("%s\n",strnstr(s1,s2,-1));
// }

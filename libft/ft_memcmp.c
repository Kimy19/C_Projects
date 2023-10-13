/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:22:25 by yaekim            #+#    #+#             */
/*   Updated: 2023/10/13 15:05:09 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	i = 0;
	while (*str1 && *str2 && i < n)
	{
		if (*str1 == *str2)
		{
			i++;
			str1++;
			str2++;
		}
		else
			return (*str1 - *str2);
	}
	if (i == n)
		return (0);
	else
		return (*str1 - *str2);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
// 	char str1[] = "ab";
// 	char str2[] = "abcd";
// 	char *s1 = str1;
// 	char *s2 = str2;
// 	int	n = 3;
// 	printf("%d\n",ft_memcmp(s1,s2,n));
// 	printf("%d\n",memcmp(s1,s2,n));
// }
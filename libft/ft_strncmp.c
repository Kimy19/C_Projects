/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:59:30 by yaekim            #+#    #+#             */
/*   Updated: 2023/10/11 15:21:16 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while (*s1 && *s2 && i < n)
	{
		if (*s1 == *s2)
		{
			i++;
			s1++;
			s2++;
		}
		else
			return ((unsigned char)*s1 - (unsigned char)*s2);
	}
	if (i == n)
		return (0);
	else
		return ((unsigned char)*s1 - (unsigned char)*s2);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
// 	char str1[] = "ab";
// 	char str2[] = "abcd";
// 	char *s1 = str1;
// 	char *s2 = str2;
// 	int	n = 33;
// 	printf("%d\n",ft_strncmp(s1,s2,n));
// 	printf("%d\n",strncmp(s1,s2,n));
// }
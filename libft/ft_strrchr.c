/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:22:58 by yaekim            #+#    #+#             */
/*   Updated: 2023/10/11 20:31:07 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*result;

	result = 0;
	while (*s)
	{
		if (*s == c)
			result = (char *)s;
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (result);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
// 	char *str= "abcad";

// 	printf("%s\n",strrchr(str,0));
// 	printf("%s\n",ft_strrchr(str,0));
// }
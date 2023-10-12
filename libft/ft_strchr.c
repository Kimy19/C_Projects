/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:23:27 by yaekim            #+#    #+#             */
/*   Updated: 2023/10/11 20:30:26 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*(unsigned char *)s == c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
// 	char *str= "\0";

// 	printf("%s\n",strchr(str,1));
// 	printf("%s\n",ft_strchr(str,1));
// }
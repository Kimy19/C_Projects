/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:23:27 by yaekim            #+#    #+#             */
/*   Updated: 2023/10/22 17:12:32 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
// 	char *str= "\0";
// 	char *str1 = "abc";

// 	printf("%d\n",(int)ft_strchr(str1,'\0'));
// 	printf("%d\n",(int)strchr(str1,'\0'));

// 	printf("%s\n",strchr(str,1));
// 	printf("%s\n",ft_strchr(str,1));
// }
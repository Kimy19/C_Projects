/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:06:02 by yaekim            #+#    #+#             */
/*   Updated: 2023/10/11 21:00:35 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*temp;
	const unsigned char	*s;
	int					i;

	temp = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (temp <= s)
	{
		while (len--)
			*temp++ = *s++;
	}
	else
	{
		temp += len;
		s += len;
		while (len--)
			*--temp = *--s;
	}
	return (dst);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char src[] = "abcdef";
// 	char dst[] = "zzzzzz";
// 	char src1[] = "abcdef";
// 	char dst1[] = "zzzzzz";
// 	ft_memmove(src+1,src,7);
// 	printf("%s\n",src);

// 	memmove(src1+1,src1,7);

// 	printf("%s",src1);
// }
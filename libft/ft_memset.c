/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:18:36 by yaekim            #+#    #+#             */
/*   Updated: 2023/10/13 16:46:31 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*temp;

	temp = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		*temp = c;
		temp++;
		i++;
	}
	return (b);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *a;

// 	a = ft_memset(a,'C',3);
// 	for(int i=0; i<3; i++)
// 		printf("%c",a[i]);
// 	return (0);
// }
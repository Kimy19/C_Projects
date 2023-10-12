/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:18:36 by yaekim            #+#    #+#             */
/*   Updated: 2023/10/11 20:00:54 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		*(unsigned char *)b = c;
		b++;
		i++;
	}
	return (b);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *a;

// 	ft_memset(a,'C',3);
// 	for(int i=0; i<3; i++)
// 		printf("%c",a[i]);
// 	return (0);
// }
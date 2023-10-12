/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:16:16 by yaekim            #+#    #+#             */
/*   Updated: 2023/10/11 17:45:44 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)s = 0;
		s++;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	mem = malloc(size * count);
	if (!mem)
		return (0);
	ft_bzero(mem, count);
	return (mem);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int *p;

// 	p = (int *)ft_calloc(5,sizeof(int));
// 	for(int i = 0; i<7; i++)
// 		printf("%d\n",p[i]);
// }
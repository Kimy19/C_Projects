/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:16:16 by yaekim            #+#    #+#             */
/*   Updated: 2023/10/20 22:41:17 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	mem = malloc(size * count);
	if (!mem)
		return (0);
	ft_memset(mem, 0, size * count);
	return (mem);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	int *p1;
// 	int *p2;
// 	size_t n= 10;

// 	p1 = (int *)ft_calloc(n, 0);
// 	p2 = (int *)calloc(n, 0);

//  	if (p2 == ((void *)0))
//  		printf("fail");
// 	printf("success");

// printf("%d\n",memcmp(p1,p2, n * sizeof(int)));

// for(int i = 0; i<n; i++)
// 	printf("%d",p1[i]);
// }
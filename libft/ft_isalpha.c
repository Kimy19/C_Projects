/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:31:19 by yaekim            #+#    #+#             */
/*   Updated: 2023/10/06 17:49:49 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

// #include <ctype.h>
// #include <stdio.h>
// int main(void)
// {
// 	char c = '*';
// 	printf("%d\n",isalpha(c));
// 	printf("%d",ft_isalpha(c));
// }
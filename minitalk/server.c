/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:47:44 by yaekim            #+#    #+#             */
/*   Updated: 2024/04/16 14:46:05 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_message(int signal)
{
	static int		bit;
	static char		temp;

	if (signal == SIGUSR1)
		temp = temp | (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", temp);
		bit = 0;
		temp = 0;
	}
}

int	main(void)
{
	ft_printf("[Server started]\n");
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, handle_message);
	signal(SIGUSR2, handle_message);
	while (1)
	{
		pause();
	}
	return (0);
}

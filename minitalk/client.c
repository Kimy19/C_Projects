/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:46:38 by yaekim            #+#    #+#             */
/*   Updated: 2024/04/16 17:13:33 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(pid_t pid, char c)
{
	int	bit;
	int	temp;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)))
			temp = kill(pid, SIGUSR1);
		else
			temp = kill(pid, SIGUSR2);
		if (temp == -1)
		{
			ft_printf("Error: Sending signal");
			exit(0);
		}
		usleep(90);
		bit++;
	}
}

void	send_message(pid_t pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i] != '\0')
	{
		send_signal(pid, msg[i]);
		i++;
	}
	send_signal(pid, '\n');
	send_signal(pid, '\0');
}

int	main(int argc, char *argv[])
{
	int		i;
	pid_t	pid;

	i = 1;
	if (argc != 3)
	{
		ft_printf("Error: Incorrect number of parameter\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 0 || pid > 99999)
	{
		ft_printf("Error: Wrong pid\n");
		return (0);
	}
	send_message(pid, argv[2]);
	return (0);
}

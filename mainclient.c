/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainclient.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:45:10 by mea               #+#    #+#             */
/*   Updated: 2022/03/18 10:57:29 by mea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "minitalk.h"

void	ft_client(int pid, char *msg)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (msg[j] != 0)
	{
		i = 0;
		while (i < 8)
		{
			if (((msg[j] >> i) & 1) == 1)
				kill(pid, SIGUSR2);
			if (((msg[j] >> i) & 1) == 0)
				kill(pid, SIGUSR1);
			i++;
			usleep(200);
		}
		j++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		return (EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	ft_client(pid, argv[2]);
	return (0);
}

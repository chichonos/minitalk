/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainserver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:39:21 by mea               #+#    #+#             */
/*   Updated: 2022/03/16 13:23:54 by mea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "minitalk.h"

void	signal_handler(int signal)
{
	static char	code;
	static int	index;

	if (signal == SIGUSR1)
	{
		index++;
	}
	else if (signal == SIGUSR2)
	{
		code |= 1 << index;
		index++;
	}
	if (index == 8)
	{
		write(1, &code, 1);
		index = 0;
		code = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	(void) argv;
	(void) argc;
	pid = getpid();
	ft_printf("Server PID : %d\n", pid);
	signal(SIGUSR2, signal_handler);
	signal(SIGUSR1, signal_handler);
	while (1)
		pause();
}

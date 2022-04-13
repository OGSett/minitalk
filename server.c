/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mekk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 00:02:44 by yel-mekk          #+#    #+#             */
/*   Updated: 2022/04/11 00:02:47 by yel-mekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sig_handler(int signum, siginfo_t *info)
{
	static int	indx = 0;
	static char	g_char = 0;
	static int	currentpid = 0;

	if (currentpid == 0)
		currentpid = info->si_pid;
	if (currentpid != info->si_pid)
	{
		indx = 0;
		g_char = 0;
		currentpid = info->si_pid;
	}
	if (signum == SIGUSR1)
		g_char = g_char | (1 << indx++);
	if (signum == SIGUSR2)
		indx++;
	if (indx == 8)
	{	
		write(1, &g_char, 1);
		indx = 0;
		g_char = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	new_behaviour;

	new_behaviour.sa_handler = (void *)&sig_handler;
	new_behaviour.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_printf("%d\n", pid);
	sigaction(SIGUSR1, &new_behaviour, NULL);
	sigaction(SIGUSR2, &new_behaviour, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}

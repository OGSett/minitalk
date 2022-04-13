/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mekk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 00:02:18 by yel-mekk          #+#    #+#             */
/*   Updated: 2022/04/11 00:02:24 by yel-mekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sighandler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("Talked Successfully\n");
}

static char	*ascii_to_binary(char c)
{
	char	*binary_chain;
	int		i;
	int		index;

	index = 0;
	binary_chain = malloc(9);
	i = 7;
	while (i >= 0)
		binary_chain[index ++] = ((c >> i--) & 1) + '0';
	binary_chain[8] = '\0';
	return (binary_chain);
}

static void	send_8bit_blocks(int pid, char	*binary_chain)
{
	int	i;

	i = 8;
	while (--i >= 0)
	{
		if (binary_chain[i] == '1')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(600);
	}
}

int	secure_cases(int	*ac, int	*pid, char	*av)
{
	if (*ac != 3)
		return (-1);
	*pid = compute_num(av);
	if (*pid <= 0 || kill(*pid, 0) == -1)
		return (-1);
	return (0);
}

int	main(int ac, char **av)
{
	char	*binary_chain;
	int		i;
	int		pid;

	i = -1;
	signal(SIGUSR1, (void *)&sighandler);
	if (secure_cases(&ac, &pid, &*av[1]) == -1)
	{
		ft_printf("please recheck your arguments!\n");
		return (-1);
	}
	while (av[2][++i])
	{
		binary_chain = ascii_to_binary(av[2][i]);
		send_8bit_blocks(pid, binary_chain);
		free(binary_chain);
	}
	if (!av[2][i])
	{
		binary_chain = ascii_to_binary(0);
		send_8bit_blocks(pid, binary_chain);
		free(binary_chain);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:24:30 by mel-behc          #+#    #+#             */
/*   Updated: 2022/09/27 10:24:32 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	ft_norm(void)
{
	write (1, "exit\n", 5);
	g_mode.g_exit = 0;
	exit (0);
}

int	ft_exit(t_args cmd)
{
	int	i;
	int	j;

	i = 0;
	if (cmd.arg[1] && !cmd.arg[2])
	{
		while (cmd.arg[1][i])
		{
			j = 0;
			if (cmd.arg[1][j] == '-')
				ft_negativenum(j, cmd);
			else
				ft_postifnum(j, cmd);
			i++;
		}
	}
	else if (cmd.arg[1] && cmd.arg[1])
	{
		printf("exit\n");
		printf ("Minishell: exit: too many arguments\n");
		g_mode.g_exit = 127;
	}
	else
		ft_norm();
	return (0);
}

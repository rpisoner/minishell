/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:34:09 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/19 12:37:31 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_command_num(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_numeric_arg(t_mini *mini, char **str)
{
	int	i;

	i = 0;
	while (str[1][i])
	{
		if (ft_isdigit(str[1][i]) == 0)
		{
			printf("minishell: exit: %s: a numeric argument is required",
				str[1]);
			mini->status = 2;
			return (1);
		}
		i++;
	}
	return (0);
}

void	do_exit(t_mini *mini, char **str)
{
	printf("exit\n");
	mini->status = 0;
	if (check_command_num(str) > 2)
	{
		mini->status = 0;
		printf("minishell: exit: too many arguments\n");
		return ;
	}
	else if (str[1])
	{
		if (check_numeric_arg(mini, str) == 1)
			exit (2);
		mini->status = ft_atoi(str[1]);
	}
	free_stuff(mini);
	close_fds(mini);
	exit (mini->status);
}

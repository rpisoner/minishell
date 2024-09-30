/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:34:09 by jolivare          #+#    #+#             */
/*   Updated: 2024/09/30 14:26:49 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_command_num(t_mini *mini)
{
	int	i;

	i = 0;
	while (mini->input.words[i])
		i++;
	return (i);
}

int	check_numeric_arg(t_mini *mini)
{
	int	i;

	i = 0;
	while (mini->input.words[1][i])
	{
		if (ft_isdigit(mini->input.words[1][i]) == 0)
		{
			printf("minishell: exit: %s: a numeric argument is required",
				mini->input.words[1]);
			mini->status = 2;
			return (1);
		}
		i++;
	}
	return (0);
}

void	do_exit(t_mini *mini)
{
	printf("exit\n");
	mini->status = 0;
	if (check_command_num(mini) > 2)
	{
		mini->status = 0;
		printf("minishell: exit: too many arguments\n");
		return ;
	}
	else if (mini->input.words[1])
	{
		if (check_numeric_arg(mini) == 1)
			exit (2);
		mini->status = ft_atoi(mini->input.words[1]);
	}
	exit (mini->status);
}

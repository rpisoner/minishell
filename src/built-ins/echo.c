/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:46:41 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/09 11:43:49 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	manage_echo_status(t_mini *mini, int i)
{
	if (mini->meta_char && ft_strcmp(mini->input.words[i], "?") == 0)
	{
		if (mini->input.words[i + 1] != NULL)
			return (1);
		else if (!mini->input.words[i + 1])
			return (2);
	}
	return (0);
}

static int	manage_echo_new_line(t_mini *mini, int i)
{
	if (ft_strcmp(mini->input.words[i], "-n") == 0)
	{
		mini->line = 1;
		if (mini->input.words[i + 1] != NULL)
			return (1);
		return (2);
	}
	return (0);
}

static void	print_new_line(t_mini *mini)
{
	if (!mini->line)
		printf("\n");
	mini->line = 0;
}

void	do_echo(t_mini *mini, int i)
{
	while (mini->input.words[++i])
	{
		if (manage_echo_new_line(mini, i) == 1)
		{
			while (ft_strcmp(mini->input.words[i], "-n") == 0)
				i++;
		}
		else if (manage_echo_new_line(mini, i) == 2)
			return ;
		if (manage_echo_status(mini, i) == 1)
		{
			printf("%d ", mini->status);
			i++;
		}
		else if (manage_echo_status(mini, i) == 2)
		{
			printf("%d\n", mini->status);
			return ;
		}
		if (mini->input.words[i + 1] == NULL)
			break ;
		printf("%s ", mini->input.words[i]);
	}
	printf("%s", mini->input.words[i]);
	print_new_line(mini);
}

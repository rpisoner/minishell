/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:46:41 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/07 15:32:28 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	manage_echo_status(t_mini *mini, int i)
{
	if (mini->meta_char && ft_strcmp(mini->input.words[i], "?") == 0)
	{
		printf("%d", mini->status);
		if (mini->input.words[i + 1] != NULL)
		{
			printf(" ");
			return (1);
		}
		else if (!mini->input.words[i + 1])
		{
			printf("\n");
			return (0);
		}
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
		return (0);
	}
	return (0);
}

void	do_echo(t_mini *mini, int i)
{
	i += 1;
	while (mini->input.words[i])
	{
		if (manage_echo_new_line(mini, i))
			i++;
		if (manage_echo_status(mini, i))
			i++;
		if (mini->input.words[i + 1] == NULL)
			break ;
		printf("%s ", mini->input.words[i]);
		i++;
	}
	printf("%s", mini->input.words[i]);
	if (!mini->line)
		printf("\n");
	mini->line = 0;
}


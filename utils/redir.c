/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:57:29 by jolivare          #+#    #+#             */
/*   Updated: 2024/09/17 16:15:27 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	manage_redir(t_mini *mini)
{
	int	i;
	int	j;

	i = 0;
	while (mini->parsed[i])
	{
		j = 0;
		while (mini->parsed[i]->cmd[j])
		{
			if (ft_strcmp(mini->parsed[i]->cmd[j], ">") == 0)
			{
				mini->parsed[i]->outfile = open(mini->parsed[i]->cmd[j + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
				mini->parsed[i]->cmd[j] = NULL;
			}
			else if (ft_strcmp(mini->parsed[i]->cmd[j], ">>") == 0)
			{
				mini->parsed[i]->outfile = open(mini->parsed[i]->cmd[j + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
				mini->parsed[i]->cmd[j] = NULL;
			}
			j++;
		}
		i++;
	}
}

void	manage_single_redir(t_mini *mini)
{
	int	i;

	i = 0;
	mini->input.outfile = -1;
	while (mini->input.words[i])
	{
		if (ft_strcmp(mini->input.words[i], ">") == 0)
		{
			mini->input.outfile = open(mini->input.words[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
			mini->input.words[i] = NULL;
		}
		else if (ft_strcmp(mini->input.words[i], ">>") == 0)
		{
			mini->input.outfile = open(mini->input.words[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
			mini->input.words[i] = NULL;
		}
		i++;
	}
}

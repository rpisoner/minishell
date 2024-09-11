/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:37:39 by jolivare          #+#    #+#             */
/*   Updated: 2024/09/11 17:42:27 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	initialize_input(t_mini *mini)
{
	int	i;

	i = 0;
	mini->cmd_num = 1;
	while (mini->input.raw_info[i])
	{
		if (mini->input.raw_info[i] == '|')
			mini->cmd_num += 1;
		i++;
	}
	mini->parsed = (t_parsed **)malloc(mini->cmd_num * sizeof(t_parsed *));
}

void	initialize_data(t_mini *mini, char **envp)
{
	mini->envp = envp;
	mini->path = search_path(envp);
	mini->quoted = 0;
	mini->ign_char = 0;
	mini->t_quote = '\0';
	mini->pipex = NULL;
}

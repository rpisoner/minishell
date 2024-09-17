/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:37:39 by jolivare          #+#    #+#             */
/*   Updated: 2024/09/17 12:01:40 by jolivare         ###   ########.fr       */
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
	mini->parsed = (t_parsed **)ft_calloc((mini->cmd_num + 1), sizeof(t_parsed *));
	i = -1;
	while (++i < mini->cmd_num)
		mini->parsed[i] = (t_parsed *)ft_calloc(1, sizeof(t_parsed));
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

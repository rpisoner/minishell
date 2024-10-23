/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:37:39 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/23 16:20:26 by rpisoner         ###   ########.fr       */
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
		quote_check(mini, i);
		if (mini->input.raw_info[i] == '|' && mini->quoted == 0)
			mini->cmd_num += 1;
		i++;
	}
	mini->quoted = 0;
	if (mini->cmd_num != 1)
	{
		mini->parsed = (t_parsed **)ft_calloc((mini->cmd_num + 1),
				sizeof(t_parsed *));
		i = -1;
		while (++i < mini->cmd_num)
			mini->parsed[i] = (t_parsed *)ft_calloc(1, sizeof(t_parsed));
		mini->parsed[i] = NULL;
	}
}

void	initialize_data(t_mini *mini, char **envp)
{
	copy_std_io(mini);
	mini->envp = modify_shlvl(copy_envp(envp));
	mini->path = search_path(envp);
	mini->quoted = 0;
	mini->ign_char = 0;
	mini->status = 0;
	mini->redir = 0;
	mini->line = 0;
	mini->is_status = 0;
	mini->unclosed_quote = 0;
	mini->here_doc = 0;
	mini->meta_char = 0;
	mini->t_quote = '\0';
}

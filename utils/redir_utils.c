/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:15:41 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/09 15:27:56 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	manage_in_redir(t_mini *mini, int i)
{
	if (ft_strcmp(mini->input.words[i], "<") == 0)
	{
		mini->input.infile = open(mini->input.words[i + 1], O_RDONLY);
		reassign_words(mini->input.words);
	}
	else if (ft_strcmp(mini->input.words[i], "<<") == 0)
	{
		mini->here_doc = 1;
		mini->input.infile = open("here_doc", O_RDONLY);
		emulate_here_doc(mini, mini->input.words[i + 1]);
		reassign_words(mini->input.words);
	}
}

void	manage_out_redir(t_mini *mini, int i)
{
	if (ft_strcmp(mini->input.words[i], ">") == 0)
	{
		mini->input.outfile = open(mini->input.words[i + 1],
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
		mini->input.words[i] = NULL;
		mini->input.words[i + 1] = NULL;
	}
	else if (ft_strcmp(mini->input.words[i], ">>") == 0)
	{
		mini->input.outfile = open(mini->input.words[i + 1],
				O_WRONLY | O_CREAT | O_APPEND, 0644);
		mini->input.words[i] = NULL;
		mini->input.words[i + 1] = NULL;
	}
}

void	manage_pipe_in(t_mini *mini, int i, int j)
{
	if (ft_strcmp(mini->parsed[i]->cmd[j], "<") == 0)
	{
		mini->parsed[i]->infile = open(mini->parsed[i]->cmd[j + 1], O_RDONLY);
		reassign_words(mini->parsed[i]->cmd);
	}
	else if (ft_strcmp(mini->parsed[i]->cmd[j], "<<") == 0)
	{
		mini->here_doc = 1;
		emulate_here_doc(mini, mini->parsed[i]->cmd[j + 1]);
		mini->parsed[i]->infile = open("here_doc", O_RDONLY);
		reassign_words(mini->parsed[i]->cmd);
	}
}

void	manage_pipe_out(t_mini *mini, int i, int j)
{
	if (ft_strcmp(mini->parsed[i]->cmd[j], ">") == 0)
	{
		mini->parsed[i]->outfile = open(mini->parsed[i]->cmd[j + 1],
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
		mini->parsed[i]->cmd[j] = NULL;
		mini->parsed[i]->cmd[j + 1] = NULL;
	}
	else if (ft_strcmp(mini->parsed[i]->cmd[j], ">>") == 0)
	{
		mini->parsed[i]->outfile = open(mini->parsed[i]->cmd[j + 1],
				O_WRONLY | O_CREAT | O_APPEND, 0644);
		mini->parsed[i]->cmd[j] = NULL;
		mini->parsed[i]->cmd[j + 1] = NULL;
	}
}

void	copy_std_io(t_mini *mini)
{
	mini->stdin = dup(STDIN_FILENO);
	mini->stdout = dup(STDOUT_FILENO);
}

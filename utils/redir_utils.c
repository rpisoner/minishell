/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:15:41 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/11 16:57:28 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	manage_in_redir(t_mini *mini, int *i)
{
	if (ft_strcmp(mini->input.words[(*i)], "<") == 0)
	{
		mini->input.infile = open(mini->input.words[(*i) + 1], O_RDONLY);
		if (mini->input.infile < 0)
		{
			perror("Error:");
			return ;
		}
		reassign_words(mini->input.words);
	}
	else if (ft_strcmp(mini->input.words[(*i)], "<<") == 0)
	{
		mini->here_doc = 1;
		mini->input.infile = open("here_doc", O_RDONLY);
		emulate_here_doc(mini, mini->input.words[(*i) + 1]);
		if (mini->input.infile < 0)
		{
			perror("Error:");
			return ;
		}
		reassign_words(mini->input.words);
	}
}

void	manage_out_redir(t_mini *mini, int *i)
{
	if (ft_strcmp(mini->input.words[(*i)], ">") == 0)
	{
		mini->input.outfile = open(mini->input.words[(*i) + 1],
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (mini->input.outfile < 0)
		{
			perror("Error:");
			return ;
		}
		mini->input.words[(*i)] = NULL;
		mini->input.words[(*i) + 1] = NULL;
		(*i)++;
	}
	else if (ft_strcmp(mini->input.words[(*i)], ">>") == 0)
	{
		mini->input.outfile = open(mini->input.words[(*i) + 1],
				O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (mini->input.outfile < 0)
		{
			perror("Error:");
			return ;
		}
		mini->input.words[(*i)] = NULL;
		mini->input.words[(*i) + 1] = NULL;
		(*i)++;
	}
}

void	manage_pipe_in(t_mini *mini, int i, int j)
{
	if (ft_strcmp(mini->parsed[i]->cmd[j], "<") == 0)
	{
		mini->parsed[i]->infile = open(mini->parsed[i]->cmd[j + 1], O_RDONLY);
		if (mini->parsed[i]->infile < 0)
		{
			perror("Error:");
			return ;
		}
		reassign_words(mini->parsed[i]->cmd);
	}
	else if (ft_strcmp(mini->parsed[i]->cmd[j], "<<") == 0)
	{
		mini->here_doc = 1;
		emulate_here_doc(mini, mini->parsed[i]->cmd[j + 1]);
		mini->parsed[i]->infile = open("here_doc", O_RDONLY);
		if (mini->parsed[i]->infile < 0)
		{
			perror("Error:");
			return ;
		}
		reassign_words(mini->parsed[i]->cmd);
	}
}

void	manage_pipe_out(t_mini *mini, int i, int *j)
{
	if (ft_strcmp(mini->parsed[i]->cmd[(*j)], ">") == 0)
	{
		mini->parsed[i]->outfile = open(mini->parsed[i]->cmd[(*j) + 1],
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (mini->parsed[i]->outfile < 0)
		{
			perror("Error:");
			return ;
		}
		mini->parsed[i]->cmd[(*j)] = NULL;
		mini->parsed[i]->cmd[(*j) + 1] = NULL;
		(*j)++;
	}
	else if (ft_strcmp(mini->parsed[i]->cmd[(*j)], ">>") == 0)
	{
		mini->parsed[i]->outfile = open(mini->parsed[i]->cmd[(*j) + 1],
				O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (mini->parsed[i]->outfile < 0)
		{
			perror("Error:");
			return ;
		}
		mini->parsed[i]->cmd[(*j)] = NULL;
		mini->parsed[i]->cmd[(*j) + 1] = NULL;
		(*j)++;
	}
}

void	copy_std_io(t_mini *mini)
{
	mini->my_stdin = dup(STDIN_FILENO);
	mini->my_stdout = dup(STDOUT_FILENO);
}

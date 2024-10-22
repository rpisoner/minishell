/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:15:41 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/22 16:09:45 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	manage_in_redir(t_mini *mini, int *i)
{
	if (ft_strcmp(mini->input.words[(*i)], "<") == 0)
	{
		mini->input.infile = open(mini->input.words[(*i) + 1], O_RDONLY);
		if (check_infile(mini->input.infile) == 1)
			return ;
		reassign_words(mini->input.words, *i);
	}
	else if (ft_strcmp(mini->input.words[(*i)], "<<") == 0)
	{
		mini->here_doc = 1;
		emulate_here_doc(mini, mini->input.words[(*i) + 1]);
		mini->input.infile = open("here_doc", O_RDONLY);
		if (check_infile(mini->input.infile) == 1)
			return ;
		reassign_words(mini->input.words, *i);
	}
}

void	manage_out_redir(t_mini *mini, int *i)
{
	if (ft_strcmp(mini->input.words[(*i)], ">") == 0)
	{
		mini->input.outfile = open(mini->input.words[(*i) + 1],
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (check_outfile(mini->input.outfile) == 1)
			return ;
		free(mini->input.words[(*i)]);
		free(mini->input.words[(*i) + 1]);
		mini->input.words[(*i)] = NULL;
		(*i)++;
	}
	else if (ft_strcmp(mini->input.words[(*i)], ">>") == 0)
	{
		mini->input.outfile = open(mini->input.words[(*i) + 1],
				O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (check_outfile(mini->input.outfile) == 1)
			return ;
		free(mini->input.words[(*i)]);
		free(mini->input.words[(*i) + 1]);
		mini->input.words[(*i)] = NULL;
		(*i)++;
	}
}

void	manage_pipe_in(t_mini *mini, int i, int j)
{
	if (ft_strcmp(mini->parsed[i]->cmd[j], "<") == 0)
	{
		mini->parsed[i]->infile = open(mini->parsed[i]->cmd[j + 1], O_RDONLY);
		if (check_infile(mini->parsed[i]->infile) == 1)
			return ;
		reassign_words(mini->parsed[i]->cmd, j);
	}
	else if (ft_strcmp(mini->parsed[i]->cmd[j], "<<") == 0)
	{
		mini->here_doc = 1;
		emulate_here_doc(mini, mini->parsed[i]->cmd[j + 1]);
		mini->parsed[i]->infile = open("here_doc", O_RDONLY);
		if (check_infile(mini->parsed[i]->infile) == 1)
			return ;
		reassign_words(mini->parsed[i]->cmd, j);
	}
}

void	manage_pipe_out(t_mini *mini, int i, int *j)
{
	if (ft_strcmp(mini->parsed[i]->cmd[(*j)], ">") == 0)
	{
		mini->parsed[i]->outfile = open(mini->parsed[i]->cmd[(*j) + 1],
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (check_outfile(mini->parsed[i]->outfile) == 1)
			return ;
		free(mini->parsed[i]->cmd[(*j)]);
		free(mini->parsed[i]->cmd[(*j) + 1]);
		mini->parsed[i]->cmd[(*j)] = NULL;
		(*j)++;
	}
	else if (ft_strcmp(mini->parsed[i]->cmd[(*j)], ">>") == 0)
	{
		mini->parsed[i]->outfile = open(mini->parsed[i]->cmd[(*j) + 1],
				O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (check_outfile(mini->parsed[i]->outfile) == 1)
			return ;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:26:01 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/11 22:33:21 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	check_first_redir(t_mini *mini)
{
	if (mini->parsed[0]->infile != -1)
	{
		dup2(mini->parsed[0]->infile, STDIN_FILENO);
		close(mini->parsed[0]->infile);
	}
	if (mini->parsed[0]->outfile != -1)
	{
		dup2(mini->parsed[0]->outfile, STDOUT_FILENO);
		close(mini->parsed[0]->outfile);
	}
	else
	{
		dup2(mini->old_pipe[WRITE], STDOUT_FILENO);
		close(mini->old_pipe[READ]);
		close(mini->old_pipe[WRITE]);
	}
}

void	check_mid_redir(t_mini *mini, int i)
{
	if (mini->parsed[i]->infile != -1)
	{
		dup2(mini->parsed[i]->infile, STDIN_FILENO);
		close(mini->parsed[i]->infile);
	}
	else
	{
		dup2(mini->old_pipe[READ], STDIN_FILENO);
		close(mini->old_pipe[READ]);
	}
	if (mini->parsed[i]->outfile != -1)
	{
		dup2(mini->parsed[i]->outfile, STDOUT_FILENO);
		close(mini->parsed[i]->outfile);
	}
	else
	{
		dup2(mini->new_pipe[WRITE], STDOUT_FILENO);
		close(mini->new_pipe[READ]);
		close(mini->new_pipe[WRITE]);
	}
}

void	check_last_redir(t_mini *mini, int i)
{
	if (mini->parsed[i]->infile != -1)
	{
		dup2(mini->parsed[i]->infile, STDIN_FILENO);
		close(mini->parsed[i]->infile);
	}
	else
	{
		dup2(mini->old_pipe[READ], STDIN_FILENO);
		close(mini->old_pipe[READ]);
	}
	if (mini->parsed[i]->outfile != -1)
	{
		dup2(mini->parsed[i]->outfile, STDOUT_FILENO);
		close(mini->parsed[i]->outfile);
	}
	close(mini->old_pipe[WRITE]);
}

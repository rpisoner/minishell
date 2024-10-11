/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:18:22 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/11 22:36:06 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	first_command(t_mini *mini)
{
	check_first_redir(mini);
	if (is_built_in(mini->parsed[0]->cmd) == 0)
	{
		if (get_values(mini, 0) == 1)
			exec_error(mini);;
	}
	check_here_doc(mini);
	if (is_built_in(mini->parsed[0]->cmd) == 1)
	{
		do_built_ins(mini, mini->parsed[0]->cmd);
		dup2(mini->old_pipe[WRITE], STDOUT_FILENO);
		close(mini->old_pipe[READ]);
		close(mini->old_pipe[WRITE]);
	}
	else
	{
		execve(mini->cmd_path, mini->parsed[0]->cmd, mini->envp);
		exec_error(mini);;
	}
	exit (mini->status);
}

void	mid_commands(t_mini *mini, int i)
{
	check_mid_redir(mini, i);
	if (is_built_in(mini->parsed[i]->cmd) == 0)
	{
		if (get_values(mini, i) == 1)
			exec_error(mini);;
	}
	check_here_doc(mini);
	if (is_built_in(mini->parsed[i]->cmd) == 1)
		do_built_ins(mini, mini->parsed[i]->cmd);
	else
	{
		execve(mini->cmd_path, mini->parsed[i]->cmd, mini->envp);
		exec_error(mini);;
	}
	exit (mini->status);
}

void	last_command(t_mini *mini, int i)
{
	check_last_redir(mini, i);
	if (is_built_in(mini->parsed[i]->cmd) == 0)
	{
		if (get_values(mini, i) == 1)
			exec_error(mini);;
	}
	check_here_doc(mini);
	if (is_built_in(mini->parsed[i]->cmd) == 1)
		do_built_ins(mini, mini->parsed[i]->cmd);
	else
	{
		execve(mini->cmd_path, mini->parsed[i]->cmd, mini->envp);
		exec_error(mini);;
	}
	exit (mini->status);
}

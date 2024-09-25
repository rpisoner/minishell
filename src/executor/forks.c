/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:32:26 by jolivare          #+#    #+#             */
/*   Updated: 2024/09/25 12:10:39 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	first_fork(t_mini *mini)
{
	pid_t	first_child;

	if (pipe(mini->old_pipe) == -1)
		pipe_error();
	first_child = fork();
	if (first_child == -1)
		exit (1);
	if (first_child == 0)
	{
		manage_redir(mini, 0);
		first_command(mini);
	}
}

static void	mid_forks(t_mini *mini)
{
	pid_t	middle_child;
	int		i;
	
	i = 1;
	close(mini->old_pipe[WRITE]);
	while (i < mini->cmd_num)
	{
		if (pipe(mini->new_pipe) == -1)
			pipe_error();
		middle_child = fork();
		if (middle_child == -1)
			exit (1);
		if (middle_child == 0)
		{
			manage_redir(mini, i);
			mid_commands(mini, i);
		}
		close(mini->old_pipe[READ]);
		mini->old_pipe[READ] = mini->new_pipe[READ];
		close(mini->new_pipe[WRITE]);
		i++;
	}
}

static void	last_fork(t_mini *mini)
{
	pid_t	last_child;
	
	last_child = fork();
	mini->last_child = last_child;
	if (last_child == -1)
		exit (1);
	if (last_child == 0)
	{
		manage_redir(mini, mini->cmd_num - 1);
		last_command(mini, mini->cmd_num - 1);
	}
}

void	execute_fork(t_mini *mini)
{
	first_fork(mini);
	mid_forks(mini);
	last_fork(mini);
}

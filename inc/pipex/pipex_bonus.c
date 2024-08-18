/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 12:19:20 by jolivare          #+#    #+#             */
/*   Updated: 2024/08/18 14:15:29 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	close_parent(t_pipe *pipex)
{
	pid_t	current_child;
	int		status;

	close(pipex->tube[0]);
	while (1)
	{
		current_child = waitpid(-1, &status, 0);
		if (current_child <= 0)
			break ;
		if (current_child == pipex->last_child)
			pipex->status = WEXITSTATUS(status);
	}
	if (pipex->here_doc == 1)
		unlink("here_doc");
}

int	pipex(t_mini *mini)
{
	

	int i = 0;
	while (mini->input->cmds[i])
	{
		if (ft_strcmp(mini->input->cmds[i], "<<") == 0)
		{
			pipex.arg_i = 4;
			pipex.here_doc = 1;
			write_here_doc(mini->input->cmds[i], &pipex);
		}
		else
		{
			pipex.here_doc = 0;
			pipex.arg_i = 3;
		}
		i++;
	}
	do_fork(&pipex);
	if (pipex.last_child > 0)
		close_parent(&pipex);
	exit(pipex.status);
}

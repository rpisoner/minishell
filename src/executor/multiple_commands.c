/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:06:56 by jolivare          #+#    #+#             */
/*   Updated: 2024/09/30 12:58:36 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	close_father(t_mini *mini)
{
	pid_t	current_child;
	int		status;

	close(mini->old_pipe[READ]);
	while (1)
	{
		current_child = waitpid(-1, &status, 0);
		if (current_child <= 0)
			break ;
		if (current_child == mini->last_child)
			mini->status = WEXITSTATUS(status);
	}
}

void	multiple_commands(t_mini *mini)
{
	execute_fork(mini);
	if (mini->last_child > 0)
		close_father(mini);
}

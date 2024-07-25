/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 00:41:22 by jolivare          #+#    #+#             */
/*   Updated: 2024/07/24 16:14:03 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/**Si hay más de un comando hacemos como en el pipex, si no hardcodeada histórica*/

void	one_cmd(t_exec *exec)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
		pid_error();
	if (pid == 0)
		// función que ejecute el único comando
	waitpid(pid, &status, 0);
	exec->status = WEXITSTATUS(status);	
}
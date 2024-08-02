/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 00:41:22 by jolivare          #+#    #+#             */
/*   Updated: 2024/08/02 11:48:05 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/**Si hay más de un comando hacemos como en el pipex, si no hardcodeada histórica*/

/*
void	one_cmd(t_mini *mini)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
		pid_error();
	if (pid == 0)
		// función que ejecute el único comando
	waitpid(pid, &status, NULL);
	mini->status = WEXITSTATUS(status);	
}
*/

void	execute(t_mini *mini)
{
	pid_t	child;
	char	*command;

	command = "ls -la";
	child = fork();
	if (child == 0)
	{
		execve("/bin/ls", &command, mini->envp);
		perror("");
	}
}

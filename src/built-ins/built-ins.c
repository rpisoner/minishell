/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:59:20 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/11 11:04:18 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	is_built_in(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (ft_strcmp(str[i], "env") == 0)
			return (1);
		else if (ft_strcmp(str[i], "pwd") == 0)
			return (1);
		else if (ft_strcmp(str[i], "cd") == 0)
			return (1);
		else if (ft_strcmp(str[i], "exit") == 0)
			return (1);
		else if (ft_strcmp(str[i], "export") == 0)
			return (1);
		else if (ft_strcmp(str[i], "unset") == 0)
			return (1);
		else if (ft_strcmp(str[i], "echo") == 0)
			return (1);
	}
	return (0);
}

void	do_built_ins(t_mini *mini, char **str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (ft_strcmp(str[i], "env") == 0)
			get_env(mini);
		else if (ft_strcmp(str[i], "pwd") == 0)
			do_pwd(mini);
		else if (ft_strcmp(str[i], "cd") == 0)
			do_cd(mini, str, i);
		else if (ft_strcmp(str[i], "exit") == 0)
			do_exit(mini, str);
		else if (ft_strcmp(str[i], "export") == 0)
			do_export(mini, str, i);
		else if (ft_strcmp(str[i], "unset") == 0)
			do_unset(mini, str);
		else if (ft_strcmp(str[i], "echo") == 0)
			do_echo(mini, str, i);
	}
}

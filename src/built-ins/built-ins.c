/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:59:20 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/22 17:14:41 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	is_built_in(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (ft_strcmp(str[i], "env") == 0 && !check_previous_pos(str, i))
			return (1);
		else if (ft_strcmp(str[i], "pwd") == 0 && !check_previous_pos(str, i))
			return (1);
		else if (ft_strcmp(str[i], "cd") == 0 && !check_previous_pos(str, i))
			return (1);
		else if (ft_strcmp(str[i], "exit") == 0 && !check_previous_pos(str, i))
			return (1);
		else if (ft_strcmp(str[i], "export") == 0 && \
				!check_previous_pos(str, i))
			return (1);
		else if (ft_strcmp(str[i], "unset") == 0 && !check_previous_pos(str, i))
			return (1);
		else if (ft_strcmp(str[i], "echo") == 0 && !check_previous_pos(str, i))
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
		if (ft_strcmp(str[i], "env") == 0 && !check_previous_pos(str, i))
			get_env(mini);
		else if (ft_strcmp(str[i], "pwd") == 0 && !check_previous_pos(str, i))
			do_pwd(mini);
		else if (ft_strcmp(str[i], "cd") == 0 && !check_previous_pos(str, i))
			do_cd(mini, str, i);
		else if (ft_strcmp(str[i], "exit") == 0 && !check_previous_pos(str, i))
			do_exit(mini, str);
		else if (ft_strcmp(str[i], "export") == 0 && \
			!check_previous_pos(str, i))
			do_export(mini, str, i);
		else if (ft_strcmp(str[i], "unset") == 0 && !check_previous_pos(str, i))
			do_unset(mini, str);
		else if (ft_strcmp(str[i], "echo") == 0 && !check_previous_pos(str, i))
			do_echo(mini, str, i);
	}
}

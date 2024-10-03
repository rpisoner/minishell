/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:59:20 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/03 12:03:47 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	is_built_in(t_mini *mini)
{
	int	i;

	i = -1;
	while (mini->input.words[++i])
	{
		if (ft_strcmp(mini->input.words[i], "env") == 0)
			return (1);
		else if (ft_strcmp(mini->input.words[i], "pwd") == 0)
			return (1);
		else if (ft_strcmp(mini->input.words[i], "cd") == 0)
			return (1);
		else if (ft_strcmp(mini->input.words[i], "exit") == 0)
			return (1);
		else if (ft_strcmp(mini->input.words[i], "export") == 0)
			return (1);
		else if (ft_strcmp(mini->input.words[i], "unset") == 0)
			return (1);
	}
	return (0);
}

void	execute_built_ins(t_mini *mini)
{
	int	i;

	i = -1;
	while (mini->input.words[++i])
	{
		if (ft_strcmp(mini->input.words[i], "env") == 0)
			get_env(mini);
		else if (ft_strcmp(mini->input.words[i], "pwd") == 0)
			do_pwd(mini);
		else if (ft_strcmp(mini->input.words[i], "cd") == 0)
			do_cd(mini, i);
		else if (ft_strcmp(mini->input.words[i], "exit") == 0)
			do_exit(mini);
		else if (ft_strcmp(mini->input.words[i], "export") == 0)
			return ;
		else if (ft_strcmp(mini->input.words[i], "unset") == 0)
			do_unset(mini);
	}
}

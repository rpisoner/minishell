/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:34:32 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/07 16:11:14 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*get_prev_path(t_mini *mini)
{
	int		i;
	char	*prev;

	i = search_on_env(mini->envp, "OLDPWD");
	if (i == -1)
	{
		mini->status = 1;
		printf("minishell: cd: OLDPWD not set\n");
		return (NULL);
	}
	prev = ft_strdup(&mini->envp[i][7]);
	if (!prev)
		malloc_error();
	printf("%s\n", prev);
	return (prev);
}

void	update_env(t_mini *mini, char *old_pwd, char *new_pwd)
{
	int		i;
	char	*new;

	i = search_on_env(mini->envp, "PWD");
	if (i >= 0)
	{
		new = ft_strjoin("PWD=", new_pwd);
		if (!new)
			malloc_error();
		free(mini->envp[i]);
		mini->envp[i] = new;
	}
	i = search_on_env(mini->envp, "OLDPWD");
	if (i == -1)
	{
		mini->envp = insert_into_env(mini->envp, ft_strjoin("OLDPWD=", old_pwd));
		if (!mini->envp)
			malloc_error();
	}
	else
		return ;
}

char	*get_target(t_mini *mini, int i)
{
	int		j;
	char	*path;
	
	if (ft_strcmp(mini->input.words[i + 1], "~") != 0 && mini->input.words[i + 1])
	{
		if (ft_strcmp(mini->input.words[i + 1], "-") == 0)
			return (get_prev_path(mini));
		path = ft_strdup(mini->input.words[i + 1]);
		if (!path)
			malloc_error();
		return (path);
	}
	j = search_on_env(mini->envp, "HOME");
	if (j < 0)
	{
		printf("Minishell: cd: HOME not set\n");
		return (NULL);
	}
	path = ft_strdup(&mini->envp[j][5]);
	return (path);
}

void	do_cd(t_mini *mini, int i)
{
	char	*target;
	char	*new_dir;
	char	*old_dir;
	int		j;

	old_dir = getcwd(NULL, 0);
	if (!old_dir)
	{
		j = search_on_env(mini->envp, "HOME");
		if (j >= 0)
		{
			target = ft_strdup(&mini->envp[j][5]);
			if (chdir(target) < 0)
			{
				printf("Minishell: cd %s: no such file or directory\n", target);
				mini->status = 1;
				free(target);
				return ;
			}
			mini->status = 0;
			new_dir = getcwd(NULL, 0);
			update_env(mini, target, new_dir);
			free(target);
			free(new_dir);
			return ;
		}
	}
	target = get_target(mini, i);
	if (!target)
	{
		free(old_dir);
		return ;
	}
	if (chdir(target) < 0)
	{
		printf("Minishell: cd %s: no such file or directory\n", target);
		mini->status = 1;
		free(target);
		free (old_dir);
		return ;
	}
	mini->status = 0;
	new_dir = getcwd(NULL, 0);
	if (ft_strcmp(old_dir, new_dir) != 0)
		update_env(mini, old_dir, new_dir);
	free(old_dir);
	free(new_dir);
	free(target);
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:55:52 by jolivare          #+#    #+#             */
/*   Updated: 2024/08/26 15:29:00 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	expander(t_mini *mini)
{
	int	i;

	i = 0;
	while (mini->input.words[i])
	{
		if (mini->quoted == 1)
		{
			if (mini->t_quote == '\"')
				expand_var(mini, mini->input.words[i], i);
		}
		else
			expand_var(mini, mini->input.words[i], i);
		i++;
	}
	mini->quoted = 0;
}

void	expand_var(t_mini *mini, char *var, int i)
{
	int 	j;
	char	*expanded;
	char	*temp;
	int		start;
	
	j = 0;
	expanded = ft_strdup("");
	while (var[j])
	{
		start = j;
		while (var[j] && var[j] != '$')
				j++;
		if (start != j)
		{
			if (mini->expanded == 0)
				temp = ft_strjoin(expanded, ft_substr(var, start, j - start));
			else
				temp = ft_strjoin(expanded, ft_substr(var, start + 1, j - start));
			free(expanded);
			expanded = temp;
		}
		if (var[j] == '$')
		{
			temp = ft_strjoin(expanded, expand_single_var(mini, var, &j));
			if (temp)
			{
				mini->expansion = 1;
				free(expanded);
				expanded = temp;
				mini->expanded = 1;
			}
		}
	}
	if (mini->expansion)
	{
		free(mini->input.words[i]);
		mini->input.words[i] = expanded;
		mini->expansion = 0;
		mini->expanded = 0;
	}
	else
		free(expanded);
}

char	*search_var(t_mini *mini, char *var)
{
	int		i;
	int		len;
	char	*word;

	i = 0;
	word = var + 1;
	len = ft_strlen(word);
	while (mini->envp[i])
	{
		if (ft_strncmp(mini->envp[i], word, len) == 0 && mini->envp[i][len] == '=')
			return (&mini->envp[i][len + 1]);
		i++;
	}
	return (NULL);
}

char	*generate_correct_var(char *var, int i)
{
	char	*correct_var;
	int		len;

	len = ft_strlen(var) - i;
	correct_var = NULL;
	if (var)
		correct_var = ft_substr(var, i, len);
	return (correct_var);
}

char	*expand_single_var(t_mini *mini, char *var, int *j)
{
	int	start;
	char	*env_var;
	char	*value;
	char	*res;

	start = *j;
	res = NULL;
	while (var[*j + 1] && (ft_isalnum(var[*j + 1]) || var[*j + 1] == '_'))
		(*j)++;
	env_var = ft_substr(var, start, *j - start + 1);
	value = search_var(mini, env_var);
	if (value)
	{
		res = ft_strdup(value);
	}
	free (env_var);
	return (res);
}

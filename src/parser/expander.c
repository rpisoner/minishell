/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:55:52 by jolivare          #+#    #+#             */
/*   Updated: 2024/08/21 13:18:57 by jolivare         ###   ########.fr       */
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
	
	j = 0;
	expanded = ft_strdup("");
	while (var[j])
	{
		if (var[j] == '$')
		{
			mini->expansion = 1;
			temp = ft_strjoin(expanded, expand_single_var(mini, var, &j));
			free (expanded);
			expanded = temp;	
		}
		else if (!ft_isalnum(var[j]) && var[j] == '_')
		{
			temp = ft_strjoin_char(expanded, var[j]);
			free (expanded);
			expanded = temp;
			j++;
		}
		else
			j++;
	}
	check_expansion(mini, expanded, i);
}

char	*search_var(t_mini *mini, char *var)
{
	int		i;
	int		len;
	char	*word;

	i = 0;
	word = var + 1;
	printf("Variable en search var: [%s]\n", var);
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
	while (var[*j + 1] && (ft_isalnum(var[*j + 1]) || var[*j + 1] == '_'))
		(*j)++;
	env_var = ft_substr(var, start, *j - start + 1);
	value = search_var(mini, env_var);
	if (value)
		res = ft_strdup(value);
	else
		res = ft_strdup("");
	free (env_var);
	return (res);
}

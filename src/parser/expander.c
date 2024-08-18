/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:55:52 by jolivare          #+#    #+#             */
/*   Updated: 2024/08/18 15:33:23 by jolivare         ###   ########.fr       */
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
}

void	expand_var(t_mini *mini, char *var, int i)
{
	if (var[0] == '$')
	{
		char *value;

		value = search_var(mini, var);
		if (value)
		{
			free(mini->input.words[i]);
			mini->input.words[i] = ft_strdup(value);
			if (!mini->input.words[i])
				malloc_error();
		}
	}
	return ;
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
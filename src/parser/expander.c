/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:55:52 by jolivare          #+#    #+#             */
/*   Updated: 2024/08/20 15:51:23 by jolivare         ###   ########.fr       */
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
	int		j;
	char	*aux;
	char	*env_var;
	char	*value;
	
	j = 0;
	while (var[j])
	{
		//printf("Caracter comprobado: [%c]\n", var[j]);
		if (var[j] == '$')
		{
			aux = ft_substr(var, 0, j);
			env_var = generate_correct_var(var, j);
			printf("Env var: [%s]\n", env_var);
			value = search_var(mini, env_var);
			if (value)
			{
				free(mini->input.words[i]);
				mini->input.words[i] = ft_strdup(ft_strjoin(aux, value));
				if (!mini->input.words[i])
					malloc_error();
			}
		}
		j++;
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

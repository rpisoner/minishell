/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:55:52 by jolivare          #+#    #+#             */
/*   Updated: 2024/08/28 15:38:06 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	expander_setter(t_mini *mini)
{
	if (mini->expanded == 1)
		mini->expanded = 0;
}

static char	*search_var(t_mini *mini, char *var)
{
	int		i;
	int		len;
	char	*word;

	i = 0;
	word = var;
	len = ft_strlen(word);
	while (mini->envp[i])
	{
		if (ft_strncmp(mini->envp[i], word, len) == 0
			&& mini->envp[i][len] == '=')
			return (&mini->envp[i][len + 1]);
		i++;
	}
	return (NULL);
}

static char	*var_name(t_mini *mini, int i)
{
	int		aux;
	char	*var_name;

	var_name = NULL;
	if (mini->input.raw_info[i] == '$')
		i++;
	aux = i;
	while (mini->input.raw_info[i] && (ft_isalnum(mini->input.raw_info[i])
			|| mini->input.raw_info[i] == '_'))
	{
		i++;
	}
	var_name = ft_substr(mini->input.raw_info, aux, i - aux);
	return (var_name);
}

static void	annex_content(t_mini *mini, char *var_content, int *j)
{
	char	*new_word;

	if (*j > 0)
	{
		mini->input.current_word[(*j)++] = '\0';
		new_word = ft_strjoin(mini->input.current_word, var_content);
		free(mini->input.current_word);
		*j = ft_strlen(new_word);
		mini->input.current_word = (char *)malloc(sizeof(char)
				* (ft_strlen(new_word) + ft_strlen(mini->input.raw_info) + 1));
		ft_strcpy(mini->input.current_word, new_word);
		free(new_word);
	}
	else
	{
		mini->input.current_word = (char *)malloc(sizeof(char)
				* (ft_strlen(var_content) + 1));
		ft_strcpy(mini->input.current_word, var_content);
		*j = ft_strlen(var_content);
	}
}

void	expander_check(t_mini *mini, int *i, int *j)
{
	char	*variable_name;
	char	*var_content;

	variable_name = NULL;
	var_content = NULL;
	if ((mini->input.raw_info[*i] == '$' && !(mini->quoted))
		|| (mini->input.raw_info[*i] == '$' && mini->quoted
			&& mini->t_quote == '\"'))
	{
		variable_name = var_name(mini, *(i));
		var_content = search_var(mini, variable_name);
		(*i) += ft_strlen(variable_name);
		free(variable_name);
		mini->expanded = 1;
		if (!var_content)
			return ;
		annex_content(mini, var_content, j);
	}
}

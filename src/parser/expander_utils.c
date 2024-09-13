/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 23:29:28 by jolivare          #+#    #+#             */
/*   Updated: 2024/09/13 23:29:46 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ign_char_setter(t_mini *mini)
{
	if (mini->ign_char == 1)
		mini->ign_char = 0;
}

char	*search_var(t_mini *mini, char *var)
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

char	*var_name(t_mini *mini, int i)
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

void	annex_content(t_mini *mini, char *var_content, int *j)
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
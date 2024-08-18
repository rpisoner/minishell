/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:55:52 by jolivare          #+#    #+#             */
/*   Updated: 2024/08/18 14:50:42 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	expander(t_mini *mini)
{
	int	i;
	int	j;

	i = 0;
	//printf("Me llamo Jeff\n");
	while (mini->input.words[i])
	{
		j = 0;
		if (mini->quoted == 1)
		{
			if (mini->t_quote == '\'')
				printf("%s\n", mini->input.words[i]);
			else if (mini->t_quote == '\"' || !mini->quoted)
			{
				expand_var(mini, mini->input.words[i]);
			}
		}
		i++;
	}
}

void	expand_var(t_mini *mini, char *var)
{
	// int	i;
	// char	*word;

	// i = 0;
	// while (mini->input.words[i])
	// {
	// 	word = mini->input.words[i];
	// 	if (word[0] == '$')
	// 	{
	// 		char	*value;

	// 		value = search_var(mini);
	// 		if (value)
	// 			printf("%s\n", value);
	// 	}
	// 	i++;
	// }
	if (var[0] == '$')
	{
		char *value;

		value = search_var(mini, var);
		if (value)
			printf("%s\n", value);
	}
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
		//printf("strncmp value: [%d]\n", ft_strncmp(mini->envp[i], word, len));
		if (ft_strncmp(mini->envp[i], word, len) == 0 && mini->envp[i][len] == '=')
			return (&mini->envp[i][len + 1]);
		i++;
	}
	return (NULL);
}
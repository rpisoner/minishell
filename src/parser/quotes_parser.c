/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:59:08 by rpisoner          #+#    #+#             */
/*   Updated: 2024/10/19 12:41:56 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	count_quotes(char *input)
{
	int		i;
	char	quote;
	int		counter;

	i = 0;
	counter = 0;
	while (input[i])
	{
		if (input[i] == '\"' || input[i] == '\'')
		{
			quote = input[i];
			counter++;
			i++;
			while (input[i] != quote)
				i++;
		}
		i++;
	}
	return (counter * 2);
}

static void	init_stuff(t_mini *mini, char **word, int *j, int i)
{
	*j = -1;
	*word = (char *)malloc(ft_strlen(mini->input.words[i])
			- count_quotes(mini->input.words[i]) + 1);
}

static void	quote_parsing(t_mini *mini, int i)
{
	char	*word;
	int		j;
	int		n;

	n = 0;
	init_stuff(mini, &word, &j, i);
	while (mini->input.words[i][++j])
	{
		if (mini->input.words[i][j] == '\'' || mini->input.words[i][j] == '\"')
		{
			if (mini->t_quote == '\0')
				mini->t_quote = mini->input.words[i][j];
			else if (mini->input.words[i][j] == mini->t_quote)
				mini->t_quote = '\0';
			else
				word[n++] = mini->input.words[i][j];
		}
		else
			word[n++] = mini->input.words[i][j];
	}
	mini->t_quote = '\0';
	word[n] = '\0';
	free(mini->input.words[i]);
	mini->input.words[i] = ft_strdup(word);
	free(word);
}

void	parse_quotes(t_mini *mini)
{
	int	i;

	i = 0;
	while (mini->input.words[i])
	{
		if ((ft_strchr(mini->input.words[i], '\"') != 0
				|| ft_strchr(mini->input.words[i], '\'') != 0)
			&& ft_strchr(mini->input.words[i], '|') == 0
			&& ft_strchr(mini->input.words[i], '<') == 0
			&& ft_strchr(mini->input.words[i], '>') == 0)
			quote_parsing(mini, i);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:26:36 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/04 18:55:32 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	create_word(t_mini *mini, int i)
{
	mini->input.current_word = (char *)malloc(sizeof(char)
			* (next_word_size(mini, i) + 1));
	if (!mini->input.current_word)
		malloc_error();
}

void	store_word(t_mini *mini, int *j, int *k)
{
	if (mini->input.current_word && *j > 0)
	{
		mini->input.current_word[*j] = '\0';
		mini->input.words[(*k)++] = ft_strdup(mini->input.current_word);
		free(mini->input.current_word);
		*j = 0;
	}
}

static void	init_stuff(t_mini *mini, int *i, int *j, int *k)
{
	*i = -1;
	*j = 0;
	*k = 0;
	mini->input.current_word = NULL;
	mini->input.words = (char **)malloc(sizeof(char *)
			* (split_counter(mini) + 1));
	if (!mini->input.words)
		malloc_error();
}

void	lexer(t_mini *mini)
{
	int		i;
	int		j;
	int		k;

	init_stuff(mini, &i, &j, &k);
	while (mini->input.raw_info[++i] != '\0')
	{
		if ((ft_isspace(mini->input.raw_info[i]) && mini->quoted == 0))
			store_word(mini, &j, &k);
		else
		{
			checkers(mini, &i, &j, &k);
			if (j == 0 && mini->input.raw_info[i] != '|'
				&& mini->input.raw_info[i] != '>'
				&& mini->input.raw_info[i] != '<')
				create_word(mini, i);
			if (mini->ign_char == 0)
				mini->input.current_word[j++] = mini->input.raw_info[i];
			ign_char_setter(mini);
		}
	}
	store_word(mini, &j, &k);
	mini->input.words[k] = NULL;
	unclosed_quote_check(mini);
	// print_stuff(mini->input.words);
}

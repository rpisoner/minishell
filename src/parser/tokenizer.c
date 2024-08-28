/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:26:36 by jolivare          #+#    #+#             */
/*   Updated: 2024/08/28 11:22:46 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	print_stuff(char **stuff)
{
	size_t	i;

	i = 0;
	while (stuff[i])
	{
		printf("Words[%ld]: %s\n", i, stuff[i]);
		i++;
	}
	printf("Words[%ld]: %s\n", i, stuff[i]);
}

int	is_delimiter(char c)
{
	return (ft_isspace(c));
}

int	numspli(char const *s, char c)
{
	char	last;
	int		i;
	char	cont;

	last = c;
	i = 0;
	cont = 0;
	while (s[i])
	{
		if (last == c && s[i] != c)
			cont++;
		last = s[i];
		i++;
	}
	return (cont);
}

void	store_word(t_mini *mini, int *j, int *k)
{
	if (mini->input.current_word && *j > 0)
	{
		mini->input.current_word[*j] = '\0';
		mini->input.words[(*k)++] = mini->input.current_word;
		*j = 0;
	}
}

void	divide_commands(t_mini *mini)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	k = 0;
	mini->input.current_word = NULL;
	mini->input.words = (char **)malloc(sizeof(char *)
			* (numspli(mini->input.raw_info, ' ') + 1));
	while (mini->input.raw_info[++i] != '\0')
	{
		if (is_delimiter(mini->input.raw_info[i]) && mini->quoted == 0)
			store_word(mini, &j, &k);
		else
		{
			quote_check(mini, i);
			expander_check(mini, &i, &j);
			if (j == 0)
			{
				mini->input.current_word = (char *)malloc(sizeof(char)
						* (ft_strlen(mini->input.raw_info) + 1));
				if (!mini->input.current_word)
					malloc_error();
			}
			if (mini->t_quote != mini->input.raw_info[i] && mini->expanded == 0)
				mini->input.current_word[j++] = mini->input.raw_info[i];
			expander_setter(mini);
		}
	}
	store_word(mini, &j, &k);
	mini->input.words[k] = NULL;
	unclosed_quote_check(mini);
	print_stuff(mini->input.words);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:26:36 by jolivare          #+#    #+#             */
/*   Updated: 2024/08/18 14:34:48 by jolivare         ###   ########.fr       */
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
		free(stuff[i]);
		i++;
	}
	printf("Words[%ld]: %s\n", i, stuff[i]);
	free(stuff[i]);
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

static void	quote_check(t_mini *mini, int i)
{
	if (mini->input.raw_info[i] == '\''
		|| mini->input.raw_info[i] == '\"')
	{
		if (mini->quoted == 0)
		{
			mini->quoted = 1;
			mini->t_quote = mini->input.raw_info[i];
		}
		// else if (mini->quoted == 1 && mini->t_quote
		// 	== mini->input.raw_info[i])
		// 	mini->quoted = 0;
	}
}

void	store_word(t_mini *mini, char *word, int *j, int *k)
{
	if (word && *j > 0)
	{
		word[*j] = '\0';
		mini->input.words[(*k)++] = word;
		*j = 0;
	}
}

void	divide_commands(t_mini *mini)
{
	char	*word;
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	k = 0;
	word = NULL;
	printf ("num_splits: [%d]\n", (numspli(mini->input.raw_info, ' ')));
	mini->input.words = (char **)malloc(sizeof(char *)
			* (numspli(mini->input.raw_info, ' ') + 1));
	while (mini->input.raw_info[++i] != '\0')
	{
		if (is_delimiter(mini->input.raw_info[i]) && mini->quoted == 0)
			store_word(mini, word, &j, &k);
		else
		{
			quote_check(mini, i);
			if (j == 0)
			{
				word = (char *)malloc(sizeof(char)
						* (ft_strlen(mini->input.raw_info) + 1));
				if (!word)
				{
					printf("Error en malloc\n");
					exit (1);
				}
			}
			if (mini->t_quote != mini->input.raw_info[i])
				word[j++] = mini->input.raw_info[i];
		}
	}
	store_word(mini, word, &j, &k);
	mini->input.words[k] = NULL;
	//unclosed_quote_check(mini);
	expander(mini);
	print_stuff(mini->input.words);
	mini->quoted = 0;
}

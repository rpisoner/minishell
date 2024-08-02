/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:26:36 by jolivare          #+#    #+#             */
/*   Updated: 2024/08/02 14:31:49 by rpisoner         ###   ########.fr       */
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

void	divide_commands(t_mini *mini)
{
	char	*word;
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	k = 0;
	printf ("num_splits: [%d]\n", (numspli(mini->input.raw_info, ' ')));
	mini->input.words = (char **)malloc(sizeof(char *)
			* (numspli(mini->input.raw_info, ' ') + 1));
	while (mini->input.raw_info[++i] != '\0')
	{
		if (is_delimiter(mini->input.raw_info[i]))
		{
			if (j > 0)
			{
				word[j] = '\0';
				mini->input.words[k++] = word;
				j = 0;
			}
		}
		else
		{
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
			word[j++] = mini->input.raw_info[i];
		}
	}
	if (j > 0)
	{
		word[j] = '\0';
		mini->input.words[k++] = word;
	}
	mini->input.words[k] = NULL;
	print_stuff(mini->input.words);
}

/*
void	assgin_data(t_mini *mini)
{
	char **str = mini->input->words;
	int i = 0;
	int j;
	int k = 0;

	while (str[i])
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			if (str[i][j] == '-')
			{
				mini->input->flags[k++] = str[i];
			}

		}
	}
}*/

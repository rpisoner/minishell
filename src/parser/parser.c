/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:45:14 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/08 12:10:57 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	last_word(t_mini *mini, int i, int j, int k)
{
	int	l;

	l = 0;
	mini->parsed[k]->cmd = (char **)ft_calloc((i - j + 1), sizeof(char *));
	if (!mini->parsed[k]->cmd)
		malloc_error();
	while (mini->input.words[j])
	{
		mini->parsed[k]->cmd[l] = mini->input.words[j];
		j++;
		l++;
	}
	mini->parsed[k]->cmd[l] = NULL;
}

/*
void	quote_parsing(t_mini *mini, int i)
{
	char	*word;
	char	*aux_word;
	int		j;
	int		aux;

	j = 0;
	if (!word)
		malloc_error();
	while (mini->input.words[i][j])
	{
		while (mini->input.words[i][j] != '\"'
				&& mini->input.words[i][j] != '\'')
			j++;
		mini->t_quote = mini->input.words[i][j];
		if (j != 0)
			word = ft_substr(mini->input.words[i], 0, j);
		aux = j;
		ft_memcpy(word, mini->input.words[i][j], j);
		while (mini->input.words[i][j] != quote)
			j++;
		
	}
	
}*/

static void	init_stuff(int *i, int *j, int *k, int *l)
{
	*i = 0;
	*j = 0;
	*k = 0;
	*l = 0;
}

void	parse_commands(t_mini *mini)
{
	int	i;
	int	j;
	int	k;
	int	l;

	init_stuff(&i, &j, &k, &l);
	while (mini->input.words[i])
	{
		if (ft_strcmp(mini->input.words[i], "|") == 0)
		{
			l = 0;
			mini->parsed[k]->cmd = (char **)ft_calloc((i - j + 1),
					sizeof(char *));
			if (!mini->parsed[k]->cmd)
				malloc_error();
			while (i != j)
				mini->parsed[k]->cmd[l++] = mini->input.words[j++];
			mini->parsed[k]->cmd[l] = NULL;
			j = i + 1;
			k++;
		}
	//	else if (ft_strchr(mini->input.words[i], "\"") || 
	//		ft_strchr(mini->input.words[i], "\'"))
	//		quote_parsing(mini, i);
		i++;
	}
	last_word(mini, i, j, k);
	//print_parsed_cmd(mini);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:45:14 by jolivare          #+#    #+#             */
/*   Updated: 2024/09/30 13:00:52 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	last_word(t_mini *mini, int i, int j, int k)
{
	int	l;

	l = 0;
	mini->parsed[k]->cmd = (char **)ft_calloc((i - j + 1), sizeof(char *));
	while (mini->input.words[j])
	{
		mini->parsed[k]->cmd[l] = mini->input.words[j];
		j++;
		l++;
	}
}

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
			j = i + 1;
			k++;
		}
		i++;
	}
	last_word(mini, i, j, k);
	// print_parsed_cmd(mini);
}

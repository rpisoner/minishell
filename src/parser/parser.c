/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:45:14 by jolivare          #+#    #+#             */
/*   Updated: 2024/09/13 15:50:36 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	parse_commands(t_mini *mini)
{
	int	i;
	int	j;
	int k;
	int l;

	i = 0;	/* Iterar en input.words */
	k = 0;	/* Posicion del comando a guardarse  */
	l = 0;	/* Posicion del argumento dentro del comando */
	j = 0;	/* Posicion del ultimo argumento del ultimo comando  */
	while (mini->input.words[i])
	{
	// 	printf("\t· Checking: [%s]\n", mini->input.words[i]);
		if (ft_strcmp(mini->input.words[i], "|") == 0)
		{
			l = 0;
			mini->parsed[k]->cmd = (char **)ft_calloc((i - j + 1), sizeof(char *));
			if (!mini->parsed[k]->cmd)
				malloc_error();
			while (i != j)
			{
				mini->parsed[k]->cmd[l] = mini->input.words[j];
				// printf("\t[ %d ] {%s}\n", l, mini->parsed[k]->cmd[l]);
				j++;
				l++;
			}
			j = i + 1;
			k++;
		}
		i++;
	}
	l = 0;
	mini->parsed[k]->cmd = (char **)ft_calloc((i - j + 1), sizeof(char *));
	while (mini->input.words[j])
	{
		// printf("input.words: [%s]\n", mini->input.words[j]);
		mini->parsed[k]->cmd[l] = mini->input.words[j];
		j++;
		l++;
	}
	i = -1;
	while (mini->parsed[++i])
	{
		j = 0;
		while (mini->parsed[i]->cmd[j])
		{
			printf("Parsed[%d]: ", i);
			printf("Last parsed position: [%s]\n", mini->parsed[i]->cmd[j]);
			j++;
		}
		printf("\n");
	}
}

// void	parse_commands(t_mini *mini)
// {
// 	int	i;

// 	i = 0;
// 	while (ft_strcmp(mini->input.words[i], "|"))
// 	{
// 		mini
// 	}
// }

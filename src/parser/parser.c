/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:45:14 by jolivare          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/09/16 17:13:56 by jolivare         ###   ########.fr       */
=======
/*   Updated: 2024/09/17 12:13:38 by rpisoner         ###   ########.fr       */
>>>>>>> 8618c2375bb8c2060c21e1660708cb9e95db2fe7
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	last_command(t_mini *mini, int i, int j, int k)
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
	*i = 0;	/* Iterar en input.words */
	*j = 0;	/* Posicion del comando a guardarse  */
	*k = 0;	/* Posicion del argumento dentro del comando */
	*l = 0;	/* Posicion del ultimo argumento del ultimo comando  */
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
<<<<<<< HEAD
			{
				mini->parsed[k]->cmd[l] = mini->input.words[j];
				j++;
				l++;
			}
=======
				mini->parsed[k]->cmd[l++] = mini->input.words[j++];
>>>>>>> 8618c2375bb8c2060c21e1660708cb9e95db2fe7
			j = i + 1;
			k++;
		}
		i++;
	}
<<<<<<< HEAD
	store_last_words(mini, i, j, k);
	manage_redir(mini);
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
=======
	last_command(mini, i, j, k);
	print_parsed_cmd(mini);
>>>>>>> 8618c2375bb8c2060c21e1660708cb9e95db2fe7
}

void	store_last_words(t_mini *mini, int i, int j, int k)
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

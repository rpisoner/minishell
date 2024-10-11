/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:20:29 by rpisoner          #+#    #+#             */
/*   Updated: 2024/10/11 22:13:32 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	is_symbol(char c)
{
	return (c == '|');
}

int	is_redirection(char c)
{
	return (c == '>' || c == '<');
}

void	spaces(char *command, int *i, int len)
{
	while (*i < len && ft_isspace(command[*i]))
		(*i)++;
}

int	count_memory(t_mini *mini)
{
	int		i;
	int		total_memory;
	int		len;
	char	*command;

	i = 0;
	total_memory = 0;
	command = mini->input.raw_info;
	len = ft_strlen(command);
	while (i < len)
	{
		spaces(command, &i, len);
		if (command[i] == '\"')
			dquotes(command, len, &i, &total_memory);
		else if (command[i] == '\'')
			squotes(command, len, &i, &total_memory);
		else if (is_redirection(command[i]))
			redirections(command, len, &i, &total_memory);
		else if (is_symbol(command[i]))
			symbols(&i, &total_memory);
		else if (i < len && !ft_isspace(command[i]))
			advancer(command, len, &i, &total_memory);
	}
	return (total_memory);
}

int	split_counter(t_mini *mini)
{
	int	splits;

	splits = count_memory(mini);
	return (splits);
}

//ls>adios>hola>archivo1| cat |prendia      |queso          |mejos
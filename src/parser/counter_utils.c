/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:06:34 by rpisoner          #+#    #+#             */
/*   Updated: 2024/10/03 11:24:58 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	dquotes(char *command, int len, int *i, int *total_memory)
{
	(*total_memory)++;
	(*i)++;
	while (*i < len && command[*i] != '\"')
		(*i)++;
	(*i)++;
}

void	squotes(char *command, int len, int *i, int *total_memory)
{
	(*total_memory)++;
	(*i)++;
	while (*i < len && command[*i] != '\'')
		(*i)++;
	(*i)++;
}

void	redirections(char *command, int len, int *i, int *total_memory)
{
	(*total_memory)++;
	while (*i < len && is_redirection(command[*i]))
		(*i)++;
}

void	symbols(int *i, int *total_memory)
{
	(*total_memory)++;
	(*i)++;
}

void	advancer(char *command, int len, int *i, int *total_memory)
{
	(*total_memory)++;
	while (*i < len && !ft_isspace(command[*i]) && !is_symbol(command[*i])
		&& command[*i] != '\"' && command[*i] != '\''
		&& !is_redirection(command[*i]))
		(*i)++;
}

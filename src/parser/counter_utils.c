/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:06:34 by rpisoner          #+#    #+#             */
/*   Updated: 2024/10/02 15:05:22 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	dquotes(char *comando, int len, int *i, int *memoria_total)
{
	(*memoria_total)++;
	(*i)++;
	while (*i < len && comando[*i] != '\"')
		(*i)++;
	(*i)++;
}

void	squotes(char *comando, int len, int *i, int *memoria_total)
{
	(*memoria_total)++;
	(*i)++;
	while (*i < len && comando[*i] != '\'')
		(*i)++;
	(*i)++;
}

void	redirections(char *comando, int len, int *i, int *memoria_total)
{
	(*memoria_total)++;
	while (*i < len && es_redireccion(comando[*i]))
		(*i)++;
}

void	symbols(int *i, int *memoria_total)
{
	(*memoria_total)++;
	(*i)++;
}

void	advancer(char *comando, int len, int *i, int *memoria_total)
{
	(*memoria_total)++;
	while (*i < len && !ft_isspace(comando[*i]) && !es_simbolo(comando[*i])
		&& comando[*i] != '\"' && comando[*i] != '\''
		&& !es_redireccion(comando[*i]))
		(*i)++;
}

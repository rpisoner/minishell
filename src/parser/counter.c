/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:20:29 by rpisoner          #+#    #+#             */
/*   Updated: 2024/10/02 17:48:15 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	es_simbolo(char c)
{
	return (c == '|');
}

int	es_redireccion(char c)
{
	return (c == '>' || c == '<');
}

void	spaces(char *comando, int *i, int len)
{
	while (*i < len && ft_isspace(comando[*i]))
		(*i)++;
}

int	contar_memoria(t_mini *mini)
{
	int		i;
	int		memoria_total;
	int		len;
	char	*comando;

	i = 0;
	memoria_total = 0;
	comando = mini->input.raw_info;
	len = ft_strlen(comando);
	while (i < len)
	{
		spaces(comando, &i, len);
		if (comando[i] == '\"')
			dquotes(comando, len, &i, &memoria_total);
		else if (comando[i] == '\'')
			squotes(comando, len, &i, &memoria_total);
		else if (es_redireccion(comando[i]))
			redirections(comando, len, &i, &memoria_total);
		else if (es_simbolo(comando[i]))
			symbols(&i, &memoria_total);
		else if (i < len && !ft_isspace(comando[i]))
			advancer(comando, len, &i, &memoria_total);
	}
	return (memoria_total);
}

int	split_counter(t_mini *mini)
{
	int	splits;

	splits = contar_memoria(mini);
	//printf("Total splits: [%d]\n", splits);
	return (splits);
}

//ls>adios>hola>archivo1| cat |prendia      |queso          |mejos
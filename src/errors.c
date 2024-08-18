/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:58:41 by rpisoner          #+#    #+#             */
/*   Updated: 2024/08/18 14:27:10 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	unclosed_quote_check(t_mini *mini)
{
	if (mini->quoted)
	{
		printf("Error: comillas sin cerrar\n");
		return ;
	}
}

void	malloc_error(void)
{
	printf("Error en alocación de memoria\n");
	exit (1);
}

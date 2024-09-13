/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:58:41 by rpisoner          #+#    #+#             */
/*   Updated: 2024/09/05 21:37:18 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	unclosed_quote_check(t_mini *mini)
{
	if (mini->quoted)
	{
		mini->quoted = 0;
		printf("Error: comillas sin cerrar\n");
		return ;
	}
}

void	malloc_error(void)
{
	printf("Error en alocación de memoria\n");
	exit (1);
}

void	exec_error(void)
{
	perror("Error");
	exit(127);
}

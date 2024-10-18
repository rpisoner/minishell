/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isspace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:40:52 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/18 16:11:49 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_isspace(char c)
{
	if (c && (c == ' ' || c == '\n' || c == '\t'
			|| c == '\v' || c == '\f' || c == '\r'))
		return (1);
	return (0);
}

void	close_fds(t_mini *mini)
{
	close(mini->my_stdin);
	close(mini->my_stdout);
}

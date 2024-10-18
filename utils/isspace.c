/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isspace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:40:52 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/18 16:42:21 by jolivare         ###   ########.fr       */
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
	if (mini->input.infile != -1)
		close(mini->input.infile + 1);
	if (mini->input.outfile != -1)
		close(mini->input.outfile + 1);
	close(mini->my_stdin);
	close(mini->my_stdout);
	close(mini->last_in);
	close(mini->last_out);
}

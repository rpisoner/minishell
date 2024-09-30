/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:45:24 by jolivare          #+#    #+#             */
/*   Updated: 2024/09/30 12:55:27 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	check_here_doc(t_mini *mini)
{
	if (mini->here_doc == 1)
	{
		unlink("here_doc");
		mini->here_doc = 0;
	}
}

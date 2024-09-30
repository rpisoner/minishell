/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:34:42 by jolivare          #+#    #+#             */
/*   Updated: 2024/09/30 12:46:24 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	get_env(t_mini *mini)
{
	int	i;

	i = 0;
	while (mini->envp[i])
		printf("%s\n", mini->envp[i++]);
}

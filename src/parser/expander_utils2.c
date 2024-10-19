/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:09:34 by rpisoner          #+#    #+#             */
/*   Updated: 2024/10/19 17:56:20 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	valid_var_content(t_mini *mini, char *var_content)
{
	mini->ign_char = 1;
	if (!var_content)
		return (0);
	return (1);
}

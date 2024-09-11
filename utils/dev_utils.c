/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:29:46 by rpisoner          #+#    #+#             */
/*   Updated: 2024/09/04 10:30:16 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	print_stuff(char **stuff)
{
	size_t	i;

	i = 0;
	while (stuff[i])
	{
		printf("Words[%ld]: %s\n", i, stuff[i]);
		i++;
	}
	printf("Words[%ld]: %s\n", i, stuff[i]);
}

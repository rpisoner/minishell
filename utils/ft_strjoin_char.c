/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:18:40 by jolivare          #+#    #+#             */
/*   Updated: 2024/08/20 15:41:38 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*ft_strjoin_char(char *s1, char c)
{
	int		len;
	char	*res;

	len = ft_strlen(s1);
	res = (char *)malloc(sizeof(char) * (len + 2));
	if (!res)
		malloc_error();
	ft_strlcpy(res, s1, len + 1);
	res[len] = c;
	res[len + 1] = '\0';
	return (res);
}

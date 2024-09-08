/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:26:36 by jolivare          #+#    #+#             */
/*   Updated: 2024/09/08 18:26:46 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

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

int	is_delimiter(char c)
{
	return (ft_isspace(c));
}

int	numspli(char const *s, char c)
{
	char	last;
	int		i;
	char	cont;

	last = c;
	i = 0;
	cont = 0;
	while (s[i])
	{
		if (last == c && s[i] != c)
			cont++;
		last = s[i];
		i++;
	}
	return (cont);
}

void	store_word(t_mini *mini, t_command *current_cmd, int *j, int *k)
{
	if (mini->input.current_word && *j > 0)
	{
		mini->input.current_word[*j] = '\0';
		current_cmd->words[(*k)++] = mini->input.current_word;
		*j = 0;
		mini->input.current_word = NULL;
	}
}

void	divide_commands(t_mini *mini)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	k = 0;
	mini->input.current_word = NULL;
	create_new_command_node(mini);
	t_command	*current_cmd = mini->input.commands;
	current_cmd->words = (char **)malloc(sizeof(char *)
			* (numspli(mini->input.raw_info, ' ') + 1));
	while (mini->input.raw_info[++i] != '\0')
	{
		if (is_delimiter(mini->input.raw_info[i]) && mini->quoted == 0)
			store_word(mini, current_cmd, &j, &k);
		else if (mini->input.raw_info[i] == '|')
		{
			store_word(mini, current_cmd, &j, &k);
			create_new_command_node(mini);
			current_cmd = current_cmd->next;
			current_cmd->words = (char **)malloc(sizeof(char *)
					* (numspli(mini->input.raw_info, ' ') + 1));
			k = 0;
		}
		else
		{
			quote_check(mini, i);
			expander_check(mini, &i, &j);
			if (j == 0)
			{
				mini->input.current_word = (char *)malloc(sizeof(char)
						* (ft_strlen(mini->input.raw_info) + 1));
				if (!mini->input.current_word)
					malloc_error();
			}
			mini->input.current_word[j++] = mini->input.raw_info[i];
			expander_setter(mini);
		}
	}
	store_word(mini, current_cmd, &j, &k);
	printf("Hola\n");
	current_cmd->words[k] = NULL;
	unclosed_quote_check(mini);
	/**t_command *cmd_node = mini->input.commands;
    while (cmd_node)
    {
        print_stuff(cmd_node->words);
        cmd_node = cmd_node->next;
    }*/
}

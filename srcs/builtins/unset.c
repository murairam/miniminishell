/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:32:23 by rbalazs           #+#    #+#             */
/*   Updated: 2025/03/01 19:29:25 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_if_variable_exists(t_env *env, char *var)
{
	t_env	*current;

	current = env;
	if (!var)
		return (0);
	while (current)
	{
		if (!ft_strcmp(current->name, var))
			return (1);
		current = current->next;
	}
	return (0);
}

static void	free_values(t_env *current)
{
	free(current->name);
	free(current->value);
	free(current);
}

int	ft_unset(char **cmd, t_data *data)
{
	int		i;
	t_env	*current;
	t_env	*prev;

	i = 0;
	while (cmd[++i])
	{
		current = data->env;
		prev = NULL;
		while (current)
		{
			if (ft_strcmp(current->name, cmd[i]) == 0)
			{
				if (prev)
					prev->next = current->next;
				else
					data->env = current->next;
				free_values(current);
				break ;
			}
			prev = current;
			current = current->next;
		}
	}
	return (EXIT_SUCCESS);
}

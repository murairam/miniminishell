/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:46:03 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/02/28 19:04:30 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	push_node_to_env(t_data *data, char *env_line)
{
	t_env	*new_node;
	t_env	*current;

	new_node = init_env_node(env_line);
	if (!new_node)
		return ;
	current = data->env;
	if (data->env == NULL)
		data->env = new_node;
	else
	{
		current = data->env;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}

void	change_shlvl(t_data *data)
{
	t_env	*tmp;
	char	*shlvl;
	int		lvl_int;

	lvl_int = 0;
	tmp = data->env;
	while (tmp)
	{
		if (ft_strncmp(tmp->line, "SHLVL=", 6) == 0)
		{
			shlvl = ft_substr(tmp->line, 6, ft_strlen(tmp->line) - 6);
			lvl_int = ft_atoi(shlvl);
			free(shlvl);
			break ;
		}
		tmp = tmp->next;
	}
	if (lvl_int == 0)
	{
        push_node_to_env(data, "SHLVL=1");
		return ;
	}
	lvl_int++;
	shlvl = ft_itoa(lvl_int);
	tmp = data->env;
	while (tmp)
	{
		if (ft_strncmp(tmp->line, "SHLVL=", 6) == 0)
		{
			free(tmp->value);
			tmp->value = ft_strdup(shlvl);
			free(tmp->line);
			tmp->line = ft_strjoin("SHLVL=", shlvl);
			free(shlvl);
			break ;
		}
		tmp = tmp->next;
	}
}
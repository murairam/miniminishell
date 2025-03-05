/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:28:14 by rbalazs           #+#    #+#             */
/*   Updated: 2025/03/01 19:30:57 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*init_default_env(void)
{
	t_env	*new;
	t_env	*res;

	res = NULL;
	new = init_default_env_node("PWD", getcwd(NULL, 0));
	if (!new)
		return (ft_free_env(res), NULL);
	append_env_variable(&res, new);
	new = init_default_env_node("SHLVL", "1");
	if (!new)
		return (ft_free_env(res), NULL);
	append_env_variable(&res, new);
	new = init_default_env_node("_", "/usr/bin/env");
	if (!new)
		return (ft_free_env(res), NULL);
	append_env_variable(&res, new);
	append_env_variable(&res, NULL);
	return (res);
}

t_env	*init_env(char **env)
{
	t_env	*env_head;
	t_env	*new_node;
	int		i;

	env_head = NULL;
	i = 0;
	while (env && env[i])
	{
		new_node = init_env_node(env[i]);
		if (!new_node)
		{
			ft_free_env(env_head);
			return (NULL);
		}
		append_env_variable(&env_head, new_node);
		i++;
	}
	if (!env_head)
		env_head = init_default_env();
	return (env_head);
}

static char	**fill_env_array(t_env *current, char **res)
{
	int		i;
	char	*tmp;

	i = 0;
	while (current)
	{
		tmp = ft_strjoin(current->name, "=");
		if (!tmp)
			return (ft_free_tab(res), NULL);
		if (current->value)
		{
			res[i] = ft_strjoin(tmp, current->value);
			free(tmp);
			if (!res[i])
				return (ft_free_tab(res), NULL);
		}
		else
			res[i] = tmp;
		i++;
		current = current->next;
	}
	res[i] = NULL;
	return (res);
}

static int	count_env_variables(t_env *env_head)
{
	int		count;
	t_env	*current;

	count = 0;
	current = env_head;
	while (current)
	{
		if (current->name && current->value)
			count++;
		current = current->next;
	}
	return (count);
}

char	**init_env_array(t_env *env_head)
{
	char	**env_array;
	int		env_count;

	env_count = count_env_variables(env_head);
	if (env_count == 0)
		return (NULL);
	env_array = (char **)malloc(sizeof(char *) * (env_count + 1));
	if (!env_array)
		return (NULL);
	return (fill_env_array(env_head, env_array));
}

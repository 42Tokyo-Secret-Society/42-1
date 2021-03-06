/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_dump.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <ecaceres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 10:53:30 by ecaceres          #+#    #+#             */
/*   Updated: 2020/02/19 10:53:30 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int
	env_compare_by_name(t_env_var *item, char *to)
{
	if (item == NULL || to == NULL)
		return (1);
	return (ft_strcmp(item->name, to));
}

int
	env_compare_name(t_env_var *a, t_env_var *b)
{
	if (a == NULL || b == NULL)
		return (a != b);
	return (ft_strcmp(a->name, b->name));
}

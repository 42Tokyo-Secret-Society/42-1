/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_handle_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <ecaceres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:18:12 by ecaceres          #+#    #+#             */
/*   Updated: 2019/11/13 18:18:12 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void
	*engine_handle_error(char *error)
{
	ft_putendl_fd("Error", ERR);
	ft_putstr_fd(error, ERR);
	free(error);
	exit(1);
	return (NULL);
}
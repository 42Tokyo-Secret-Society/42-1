/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <ecaceres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:19:28 by ecaceres          #+#    #+#             */
/*   Updated: 2019/12/18 17:19:28 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "../tests.h"

void	ft_swap_void(void **a, void **b)
{
	void *c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_list_sort_2(t_list **begin_list, int (*cmp)())
{
	t_list	*current;
	t_list	*end;
	bool	swapped;

	if (*begin_list == 0)
		return ;
	swapped = true;
	end = 0;
	while (swapped)
	{
		swapped = false;
		current = *begin_list;
		while (1)
		{
			if (current->next == end)
				break ;
			if ((*cmp)(current->data, current->next->data) > 0)
			{
				ft_swap_void(&(current->data), &(current->next->data));
				swapped = true;
			}
			current = current->next;
		}
		end = current;
	}
}

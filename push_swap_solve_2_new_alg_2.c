/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_new_alg_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:37:36 by maweiss           #+#    #+#             */
/*   Updated: 2024/04/08 16:27:38 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_loop(t_list *tmp, int index, int size)
{
	int	i;

	i = 0;
	while (tmp)
	{
		if ((!tmp->next && tmp->cont->index > index)
			|| (!tmp->next && tmp->cont->index < index)
			|| (tmp->cont->index < index && tmp->next->cont->index > index)
			|| (tmp->cont->index < index && tmp->next->cont->index < index
				&& tmp->next->cont->index < tmp->cont->index)
			|| (tmp->cont->index > index && tmp->next->cont->index > index
				&& tmp->next->cont->index < tmp->cont->index))
		{
			if (i + 1 >= ((float)size / 2) + 1)
				return (-size + i + 1);
			else
				return (i + 1);
		}
		i++;
		tmp = tmp->next;
	}
	return (INT_MIN);
}

int	ft_find_target(t_list **lst_a, int index)
{
	t_list	*last;
	t_list	*tmp;
	int		size;
	int		i;

	i = 0;
	size = ft_lstsize(*lst_a);
	last = ft_lstlast(*lst_a);
	if ((last->cont->index > index && (*lst_a)->cont->index < last->cont->index
			&& (*lst_a)->cont->index > index)
		|| (last->cont->index < index
			&& (*lst_a)->cont->index < last->cont->index
			&& (*lst_a)->cont->index < index))
		return (0);
	tmp = *lst_a;
	return (ft_loop(tmp, index, size));
}

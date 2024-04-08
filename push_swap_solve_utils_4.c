/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_utils_4.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:37:36 by maweiss           #+#    #+#             */
/*   Updated: 2024/04/08 12:47:14 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_finish_b(t_list **lst_a, t_list **lst_b)
{
	int	size_b;
	int	size_a;
	int	dist;

	size_b = 1;
	while (size_b > 0)
	{
		size_b = ft_lstsize(*lst_b);
		size_a = ft_lstsize(*lst_a);
		ft_dist(lst_b, size_b, lst_a);
		dist = ft_cheapest(lst_b);
		if (ft_turn(lst_b, dist) == 1)
			ft_dist(lst_b, size_b, lst_a);
		ft_turn(lst_a, (*lst_b)->cont->dist_a);
		ft_pa(lst_a, lst_b, 0);
		size_b--;
	}
	return (0);
}

void	ft_dist(t_list **lst_b, int size_b, t_list **lst_a)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *lst_b;
	while (tmp)
	{
		if (i + 1 <= size_b / 2)
			tmp->cont->dist_b = i;
		else
			tmp->cont->dist_b = -(size_b) + i + 1;
		i++;
		tmp->cont->dist_a = ft_find_target(lst_a, tmp->cont->index);
		tmp = tmp->next;
	}
}

int	ft_cheapest(t_list **lst_b)
{
	t_list	*tmp;
	int		price;
	int		tmp_2;
	int		aux1 = 0;
	int		aux2 = 0;

	price = INT_MAX;

	tmp = *lst_b;
	while (tmp)
	{
		tmp_2 = ft_abs(tmp->cont->dist_a) + ft_abs(tmp->cont->dist_b);
		if (tmp_2 < price)
			price = tmp_2;
		tmp = tmp->next;
		aux1++;
	}
	tmp = *lst_b;
	while (tmp)
	{
		if (price == ft_abs(tmp->cont->dist_a) + ft_abs(tmp->cont->dist_b))
		{
			tmp->cont->target = 1;
			return (tmp->cont->dist_b);
		}
		tmp = tmp->next;
		aux2++;
	}
	return (INT_MIN);
}

int	ft_turn(t_list **lst, int dist)
{
	int		turned;

	turned = 0;
	while (dist != 0)
	{
		turned = 1;
		if (dist < 0)
		{
			ft_rra(lst, 0);
			dist++;
		}
		else
		{
			ft_ra(lst, 0);
			dist--;
		}
	}
	return (turned);
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
	if (last->cont->index > index && (*lst_a)->cont->index < last->cont->index && (*lst_a)->cont->index > index)
		return (0);
	tmp = *lst_a;
	while (tmp)
	{
		if ((tmp->cont->index < index && tmp->next
				&& tmp->next->cont->index > index)
			|| (!tmp->next && tmp->cont->index > index))
		{
			if (i + 1 > (float)size / 2)
				return (-size + i); // +1 or not??
			else
				return (i + 1);
		}
		i++;
		tmp = tmp->next;
	}
	return (INT_MIN);
}

// handling:
// all values are to the right
// check for value with the lowest price.
// lowest price = abs dist_a + abs dist_b < andere

// abs dist_b < bestimmter Wert.




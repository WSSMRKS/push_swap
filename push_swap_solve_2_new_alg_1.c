/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_new_alg_1.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:37:36 by maweiss           #+#    #+#             */
/*   Updated: 2024/04/08 16:27:31 by maweiss          ###   ########.fr       */
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
		if (ft_turn_b(lst_b, dist) == 1)
			ft_dist(lst_b, size_b, lst_a);
		ft_turn_a(lst_a, (*lst_b)->cont->dist_a);
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
		if (i + 1 <= ((float)size_b / 2) + 1)
			tmp->cont->dist_b = i;
		else
			tmp->cont->dist_b = -(size_b) + i;
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

	price = INT_MAX;
	tmp = *lst_b;
	while (tmp)
	{
		tmp_2 = ft_abs(tmp->cont->dist_a) + ft_abs(tmp->cont->dist_b);
		if (tmp_2 < price)
			price = tmp_2;
		tmp = tmp->next;
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
	}
	return (INT_MIN);
}

int	ft_turn_b(t_list **lst, int dist)
{
	int		turned;

	turned = 0;
	while (dist != 0)
	{
		turned = 1;
		if (dist < 0)
		{
			ft_rrb(lst, 0);
			dist++;
		}
		else
		{
			ft_rb(lst, 0);
			dist--;
		}
	}
	return (turned);
}

int	ft_turn_a(t_list **lst, int dist)
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

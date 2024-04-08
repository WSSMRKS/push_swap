/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_3_old_alg.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:37:36 by maweiss           #+#    #+#             */
/*   Updated: 2024/04/08 16:36:56 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_list **lst_1, t_list **lst_2, int size_2)
{
	int		dist;
	t_list	*tmp;

	while (size_2 > 0)
	{
		tmp = *lst_2;
		dist = ft_find_index(lst_1, tmp->cont->index);
		while (dist != 0 && dist != -1000000)
		{
			if (dist < 0)
			{
				ft_rra(lst_1, 0);
				dist++;
			}
			else
			{
				ft_ra(lst_1, 0);
				dist--;
			}
		}
		ft_pa(lst_1, lst_2, 0);
		size_2--;
	}
}

int	ft_find_index(t_list **lst_1, int index)
{
	int		dist_t;
	int		dist_b;
	t_list	*end_node;

	dist_t = -1;
	dist_b = -1000000;
	end_node = ft_lstlast(*lst_1);
	if ((*lst_1)->cont->index == index
		|| ((*lst_1)->cont->index > index && end_node->cont->index < index))
		return (0);
	else if (index > end_node->cont->index
		&& (*lst_1)->cont->index < end_node->cont->index)
		return (0);
	ft_calc_dist(lst_1, index, &dist_t, &dist_b);
	if (dist_t == -1 && dist_b == -1000000)
		return (0);
	if (dist_t > -(dist_b))
		return (dist_b);
	else
		return (dist_t);
}

int	ft_calc_dist(t_list **lst_a, int index, int *dist_t, int *dist_b)
{
	t_list	*tmp;
	int		i;
	int		size;

	i = 0;
	tmp = *lst_a;
	size = ft_lstsize(*lst_a);
	while (tmp)
	{
		if (tmp->next != NULL && tmp->next->cont->index < tmp->cont->index)
		{
			*dist_t = i + 1;
			*dist_b = -(size - 1) + i;
		}
		if (tmp->next != NULL && tmp->cont->index < index
			&& tmp->next->cont->index > index)
		{
			*dist_t = i + 1;
			*dist_b = -(size - 1) + i;
			break ;
		}
		tmp = tmp->next;
		i++;
	}
	return (0);
}

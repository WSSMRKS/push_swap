/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_utils_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:37:36 by maweiss           #+#    #+#             */
/*   Updated: 2024/04/08 16:30:07 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_chunk_init(int *dist_b, int *dist_t, int *i, int *ch_done)
{
	*i = 0;
	*dist_t = -1;
	*dist_b = -1000000;
	*ch_done = 1;
}

int	ft_find_chunk(t_list **lst, int chunk, int size)
{
	int		dist_t;
	int		dist_b;
	int		i;
	t_list	*tmp;
	int		chunk_done;

	ft_find_chunk_init(&dist_b, &dist_t, &i, &chunk_done);
	tmp = *lst;
	while (tmp)
	{
		if (dist_t == -1 && tmp->cont->chunk == chunk)
			dist_t = i;
		if (dist_b < -(size) + i && tmp->cont->chunk == chunk)
			dist_b = -(size) + i;
		if (tmp->cont->chunk == chunk)
			chunk_done = 0;
		tmp = tmp->next;
		i++;
	}
	if (chunk_done == 1)
		return (-1000000);
	if (dist_t > -(dist_b))
		return (dist_b);
	return (dist_t);
}

void	ft_push_b(t_list **lst_a, t_list **lst_b, int size_a, int chunks)
{
	int	dist;

	dist = 0;
	while (size_a > 3)
	{
		dist = ft_find_chunk(lst_a, chunks, size_a);
		if (dist == -1000000)
			chunks--;
		while (dist != 0 && dist != -1000000)
		{
			if (dist < 0)
			{
				ft_rra(lst_a, 0);
				dist++;
			}
			else
			{
				ft_ra(lst_a, 0);
				dist--;
			}
		}
		if (dist == 0)
			ft_pb(lst_a, lst_b, 0);
		size_a = ft_lstsize(*lst_a);
	}
}

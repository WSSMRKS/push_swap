/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_utils_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:37:36 by maweiss           #+#    #+#             */
/*   Updated: 2024/03/27 17:57:33 by maweiss          ###   ########.fr       */
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

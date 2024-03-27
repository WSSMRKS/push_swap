/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_utils_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:37:36 by maweiss           #+#    #+#             */
/*   Updated: 2024/03/27 10:49:05 by maweiss          ###   ########.fr       */
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

int	ft_find_index(t_list **lst_1, int index, int size)
{
	//solution for line issues. Make function that is returning the right distance. Pack it in return value.
	int		dist_t;
	int		dist_b;
	int		i;
	t_list	*tmp;
	t_list	*end_node;

	dist_t = -1;
	dist_b = -1000000;
	i = 0;
	end_node = ft_lstlast(*lst_1);
	if ((*lst_1)->cont->index > index && end_node->cont->index < index)
		return (0);
	else if (index > end_node->cont->index
		&& (*lst_1)->cont->index < end_node->cont->index)
		return (0);
	tmp = *lst_1;
	while (tmp)
	{
		if (tmp->next != NULL && tmp->next->cont->index < tmp->cont->index)
		{
			dist_t = i + 1;
			dist_b = -(size - 1) + i;
		}
		if (tmp->next != NULL && tmp->cont->index < index
			&& tmp->next->cont->index > index)
		{
			dist_t = i + 1;
			dist_b = -(size - 1) + i;
			break ;
		}
		tmp = tmp->next;
		i++;
	}
	if (dist_t == -1 && dist_b == -1000000)
		return (0);
	if (dist_t > -(dist_b))
		return (dist_b);
	else
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

void	ft_push_a(t_list **lst_1, t_list **lst_2, int size_2)
{
	int		dist;
	t_list	*tmp;

	while (size_2 > 0)
	{
		tmp = *lst_2;
		dist = ft_find_index(lst_1, tmp->cont->index, ft_lstsize(*lst_1));
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wssmrks <wssmrks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:37:36 by maweiss           #+#    #+#             */
/*   Updated: 2024/03/18 19:36:40 by wssmrks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_switch(int **stack_a, int *size)
{
	ft_solve(stack_a, size);
	exit(1);
}

void	ft_calc_index(t_list **lst_a, int size)
{
	int			min;
	long int	min_o;
	int			index;
	t_list		*tmp_a;

	index = 0;
	min_o = (long)-INT_MAX -2;
	while (index < size)
	{
		min = INT_MAX;
		tmp_a = *lst_a;
		while (tmp_a)
		{
			if (tmp_a->cont->value <= min && (long) tmp_a->cont->value > min_o)
				min = tmp_a->cont->value;
			tmp_a = tmp_a->next;
		}
		tmp_a = *lst_a;
		while (tmp_a)
		{
			if (tmp_a->cont->value == min)
				break ;
			tmp_a = tmp_a->next;
		}
		tmp_a->cont->index = index++;
		ft_assign_chunk(&tmp_a, size, ft_chunks(size));
		min_o = (long) min;
	}
}

void	ft_assign_chunk(t_list **lst_a, int size, int chunks)
{
	if (((float)size / chunks) > (*lst_a)->cont->index)
		(*lst_a)->cont->chunk = 0;
	if (((float)size / chunks) < (*lst_a)->cont->index)
		(*lst_a)->cont->chunk = 1;
	if (((float)size / chunks) * 2 < (*lst_a)->cont->index)
		(*lst_a)->cont->chunk = 2;
	if (((float)size / chunks) * 3 < (*lst_a)->cont->index)
		(*lst_a)->cont->chunk = 3;
	if (((float)size / chunks) * 4 < (*lst_a)->cont->index)
		(*lst_a)->cont->chunk = 4;
	if (((float)size / chunks) * 5 < (*lst_a)->cont->index)
		(*lst_a)->cont->chunk = 5;
	if (((float)size / chunks) * 6 < (*lst_a)->cont->index)
		(*lst_a)->cont->chunk = 6;
}

int	ft_chunks(int size)
{
	int	chunks;

	chunks = 1;
	if (size <= 3)
		return (chunks);
	else if (size > 3 && size <= 30)
		chunks = 2;
	else if (size > 30 && size <= 50)
		chunks = 3;
	else
	{
		while (size / chunks > 20)
			chunks++;
	}
	return (chunks);
}

int	ft_find_chunk(t_list **lst, int chunk, int size)
{
	int		dist_t;
	int		dist_b;
	int		i;
	t_list	*tmp;
	int		chunk_done;

	chunk_done = 1;
	dist_t = 0;
	dist_b = -1000000;
	i = 0;
	tmp = *lst;
	while (tmp)
	{
		if (dist_t == 0 && tmp->cont->chunk == chunk)
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
	else
		return (dist_t);
}

int	ft_find_index(t_list **lst_1, int index, int size)
{
	int		dist_t;
	int		dist_b;
	int		i;
	t_list	*tmp;
	int		chunk_done;

	chunk_done = 1;
	dist_t = 0;
	dist_b = -1000000;
	i = 0;
	tmp = *lst_1;
	while (tmp)
	{
		if (dist_t == 0 && tmp->cont->index == index)
			dist_t = i;
		if (dist_b < -(size) + i && tmp->cont->index == index)
			dist_b = -(size) + i;
		if (tmp->cont->index == index)
			chunk_done = 0;
		tmp = tmp->next;
		i++;
	}
	if (chunk_done == 1)
		return (-1000000);
	if (dist_t > -(dist_b))
		return (dist_b);
	else
		return (dist_t);
}


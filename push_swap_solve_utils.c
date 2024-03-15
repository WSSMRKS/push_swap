/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:37:36 by maweiss           #+#    #+#             */
/*   Updated: 2024/03/15 17:55:55 by maweiss          ###   ########.fr       */
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
	if ((size / chunks) > (*lst_a)->cont->index)
		(*lst_a)->cont->chunk = 0;
	if ((size / chunks) < (*lst_a)->cont->index)
		(*lst_a)->cont->chunk = ((*lst_a)->cont->index / (size / chunks));
}

int	ft_chunks(int size)
{
	int	chunks;

	chunks = 1;
	if (size <= 8)
		return (chunks);
	if (size > 8 && size <= 30)
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

int	ft_find_closest(t_list **lst, int chunk, int size)
{
	int		dist_t;
	int		dist_b;
	int		i;
	t_list	*tmp;

	dist_t = 0;
	dist_b = -1;
	i = 0;
	tmp = *lst;
	while (tmp)
	{
		if (dist_t == 0 && tmp->cont->chunk == chunk)
			dist_t = i;
		if (dist_b > -(size) + i && tmp->cont->chunk == chunk)
			dist_b = -(size) + i;
		tmp = tmp->next;
		i++;
	}
	if (dist_t > -(dist_b))
		return (dist_b);
	else
		return (dist_t);
}


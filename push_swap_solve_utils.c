/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:37:36 by maweiss           #+#    #+#             */
/*   Updated: 2024/03/25 22:02:59 by maweiss          ###   ########.fr       */
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
	static float	chunk_size;
	int				i;

	i = 1;
	chunk_size = ((float)(size - 1) / chunks);

	if (chunk_size > (*lst_a)->cont->index)
		(*lst_a)->cont->chunk = 0;
	else if (chunk_size < (*lst_a)->cont->index)
	{
		while ((float)chunk_size * i < (*lst_a)->cont->index)
			i++;
		(*lst_a)->cont->chunk = i - 1;
	}
}

int	ft_chunks(int size)
{
	int	chunks;

	chunks = 1;
	if (size <= 15)
		return (chunks);
	else if (size > 15 && size <= 50)
		chunks = 3;
	else if (size > 50 && size < 80)
		chunks = 5;
	else if (size > 80 && size <= 200)
		chunks = 7;
	else if (size > 200 && size <= 450)
		chunks = 10;
	else if (size > 450 && size <= 950)
		chunks = 12;
	else if (size > 950 && size <= 2500)
		chunks = 17;
	else
	{
		while (size / chunks > 50)
			chunks++;
	}
	return (chunks);
}

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

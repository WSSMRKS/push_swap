/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_utils_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:37:36 by maweiss           #+#    #+#             */
/*   Updated: 2024/04/08 16:03:28 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_calc_index(t_list **lst_a, int size)
{
	int			index;
	t_list		*tmp;
	t_list		*m_o;
	t_list		*m;

	index = 0;
	m_o = NULL;
	while (index < size)
	{
		m = NULL;
		tmp = *lst_a;
		while (tmp)
		{
			if ((m == NULL && (m_o == NULL
						|| tmp->cont->value > m_o->cont->value)))
				m = tmp;
			if (m != NULL && (tmp->cont->value <= m->cont->value
					&& (m_o == NULL || tmp->cont->value > m_o->cont->value)))
				m = tmp;
			tmp = tmp->next;
		}
		m->cont->index = index++;
		ft_assign_chunk(&m, size, ft_chunks(size));
		m_o = m;
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
	if (size <= 200)
		chunks = 1;
	else if (size > 200 && size <= 450)
		chunks = 3;
	else if (size > 450 && size <= 950)
		chunks = 5;
	else if (size > 950)
		chunks = 9;
	return (chunks);
}

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

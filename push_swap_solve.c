/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:37:36 by maweiss           #+#    #+#             */
/*   Updated: 2024/03/15 17:32:09 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_solve(int **stack_a, int *size)
{
	t_list	*lst_a;
	t_list	*lst_b;

	lst_a = ft_fill_lst(stack_a, size);
	lst_b = NULL;
	if (*size == 2)
		ft_sa(&lst_a, 0);
	else if (*size <= 3)
		ft_solve_3(&lst_a);
	else if (*size <= 5)
		ft_solve_5(&lst_a, &lst_b, size);
	else if (*size <= 10)
		ft_solve_10(&lst_a, &lst_b, size);
	else
		ft_solve_big(&lst_a, &lst_b, size, ft_chunks(*size));
	ft_lstfree(&lst_a);
	ft_lstfree(&lst_b);
	ft_free((void *)stack_a, 0);
}

void	ft_solve_3(t_list **lst_a)
{
	if ((*lst_a)->cont->value < (*lst_a)->next->cont->value
		&& (*lst_a)->next->cont->value > (*lst_a)->next->next->cont->value)
	{
		if ((*lst_a)->cont->value < (*lst_a)->next->next->cont->value)
		{
			ft_sa(lst_a, 0);
			ft_ra(lst_a, 0);
		}
		else
			ft_rra(lst_a, 0);
	}
	else if ((*lst_a)->cont->value > (*lst_a)->next ->cont->value
		&& (*lst_a)->next->cont->value < (*lst_a)->next->next->cont->value)
	{
		if ((*lst_a)->cont->value < (*lst_a)->next->next->cont->value)
			ft_sa(lst_a, 0);
		else
			ft_ra(lst_a, 0);
	}
	else
	{
		ft_sa(lst_a, 0);
		ft_rra(lst_a, 0);
	}
}

void	ft_solve_5(t_list **lst_a, t_list **lst_b, int *size)
{
	int	chunks;

	chunks = ft_chunks(*size);
	ft_calc_index(lst_a, *size);

	write(2, "Solving algorithm not in place yet!\n", 36);
	*lst_a = NULL;
	*lst_b = NULL;
	*size = 0;
	return ;
}

void	ft_solve_10(t_list **lst_a, t_list **lst_b, int *size)
{
	lst_a = NULL;
	lst_b = NULL;
	*size = 0;
	write(2, "Solving algorithm not in place yet!\n", 36);
	return ;
}

void	ft_solve_big(t_list **lst_a, t_list **lst_b, int *size, int chunks)
{
	int		chunk;
	int		size_a;
	// int		size_b;
	int		dist;

	chunk = chunks;
	size_a = *size;
	ft_calc_index(lst_a, *size);
	while (size_a > 3)
	{
		dist = ft_find_closest(lst_a, chunk, size_a);
		if (dist == size_a)
			chunk--;
		while (dist != 0)
		{
			if (dist < 0)
				ft_rra(lst_a, 0);
			else
				ft_ra(lst_a, 0);
		}
		if (dist == 0)
			ft_pb(lst_a, lst_b, 0);
		size_a--;
	}
	write(2, "Solving algorithm not in place yet!\n", 36);
	lst_a = NULL;
	lst_b = NULL;
	*size = 0;
	return ;
}

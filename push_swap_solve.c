/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:37:36 by maweiss           #+#    #+#             */
/*   Updated: 2024/04/08 16:34:08 by maweiss          ###   ########.fr       */
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
		ft_solve_3_l(&lst_a);
	else
		ft_solve_big(&lst_a, &lst_b, size, ft_chunks(*size));
	ft_lstfree(&lst_a);
	ft_lstfree(&lst_b);
	ft_free((void *)stack_a, 0);
}

void	ft_solve_3_l(t_list **lst_a)
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
	else if ((*lst_a)->cont->value > (*lst_a)->next->cont->value
		&& (*lst_a)->next->cont->value > (*lst_a)->next->next->cont->value)
	{
		ft_sa(lst_a, 0);
		ft_rra(lst_a, 0);
	}
}

void	ft_solve_big(t_list **lst_a, t_list **lst_b, int *size, int chunks)
{
	int	alg;

	alg = 1;
	ft_calc_index(lst_a, *size);
	ft_push_b(lst_a, lst_b, *size, chunks);
	ft_solve_3_l(lst_a);
	if (alg == 1)
		ft_finish_b(lst_a, lst_b);
	else
		ft_push_a(lst_a, lst_b, ft_lstsize(*lst_b));
	ft_0_top(lst_a);
	lst_a = NULL;
	lst_b = NULL;
	*size = 0;
	return ;
}

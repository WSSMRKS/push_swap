/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:37:36 by maweiss           #+#    #+#             */
/*   Updated: 2024/03/15 12:29:52 by maweiss          ###   ########.fr       */
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
		ft_solve_big(&lst_a, &lst_b, size);
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

// void	ft_solve_3(t_list **lst_a)
// {
// 	if (*(int)(*lst_a)->cont->value < *(int)(*lst_a)->next->cont->value
// 		&& *(int *)(*lst_a)->next->cont > *(int *)(*lst_a)->next->next->cont)
// 	{
// 		if (*(int *)(*lst_a)->cont < *(int *)(*lst_a)->next->next->cont)
// 		{
// 			ft_sa(lst_a, 0);
// 			ft_ra(lst_a, 0);
// 		}
// 		else
// 			ft_rra(lst_a, 0);
// 	}
// 	else if (*(int *)(*lst_a)->cont > *(int *)(*lst_a)->next->cont
// 		&& *(int *)(*lst_a)->next->cont < *(int *)(*lst_a)->next->next->cont)
// 	{
// 		if (*(int *)(*lst_a)->cont < *(int *)(*lst_a)->next->next->cont)
// 			ft_sa(lst_a, 0);
// 		else
// 			ft_ra(lst_a, 0);
// 	}
// 	else
// 	{
// 		ft_sa(lst_a, 0);
// 		ft_rra(lst_a, 0);
// 	}
// 	return ;
// }

void	ft_solve_5(t_list **lst_a, t_list **lst_b, int *size)
{
	write(2, "Solving algorithm not in place yet!\n", 36);
	lst_a = NULL;
	lst_b = NULL;
	*size = 0;
	return ;
}

void	ft_solve_10(t_list **lst_a, t_list **lst_b, int *size)
{
	write(2, "Solving algorithm not in place yet!\n", 36);
	lst_a = NULL;
	lst_b = NULL;
	*size = 0;
	return ;
}

void	ft_solve_big(t_list **lst_a, t_list **lst_b, int *size)
{
	write(2, "Solving algorithm not in place yet!\n", 36);
	lst_a = NULL;
	lst_b = NULL;
	*size = 0;
	return ;
}

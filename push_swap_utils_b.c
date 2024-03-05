/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:19:56 by maweiss           #+#    #+#             */
/*   Updated: 2024/03/05 14:35:48 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_list *lst_a, t_list *lst_b, int silent)
{
	if (lst_b == NULL)
	{
		ft_putstr_fd("Stack b is empty\n", 1);
		return ;
	}
	if (lst_a == NULL)
	{
		ft_putstr_fd("Stack a is empty\n", 1);
		return ;
	}
	ft_sa(lst_a, 1);
	ft_sb(lst_b, 1);
	if (silent != 1)
		ft_putstr_fd("ss\n", 1);
}

void	ft_ra(t_list *lst_a, int silent)
{
	t_list	*tmp;

	if (lst_a == NULL)
	{
		ft_putstr_fd("Stack a is empty\n", 1);
		return ;
	}
	tmp = lst_a->next;
	lst_a->next = NULL;
	ft_lstadd_back(&tmp, lst_a);
	lst_a = tmp;
	if (silent != 1)
		ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_list *lst_b, int silent)
{
	t_list	*tmp;

	if (lst_b == NULL)
	{
		ft_putstr_fd("Stack b is empty\n", 1);
		return ;
	}
	tmp = lst_b->next;
	lst_b->next = NULL;
	ft_lstadd_back(&tmp, lst_b);
	lst_b = tmp;
	if (silent != 1)
		ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_list *lst_a, t_list *lst_b, int silent)
{
	if (lst_b == NULL)
	{
		ft_putstr_fd("Stack b is empty\n", 1);
		return ;
	}
	if (lst_a == NULL)
	{
		ft_putstr_fd("Stack a is empty\n", 1);
		return ;
	}
	ft_ra(lst_a, 1);
	ft_rb(lst_b, 1);
	if (silent != 1)
		ft_putstr_fd("rr\n", 1);
}

void	ft_rra(t_list *lst_a, int silent)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (lst_a == NULL)
	{
		ft_putstr_fd("Stack a is empty\n", 1);
		return ;
	}
	tmp1 = ft_lstlast(lst_a);
	tmp2 = ft_lst2ndlast(lst_a);
	tmp2->next = NULL;
	ft_lstadd_front(&lst_a, tmp1);
	if (silent != 1)
		ft_putstr_fd("rra\n", 1);
}

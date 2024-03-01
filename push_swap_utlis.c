/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utlis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:19:56 by maweiss           #+#    #+#             */
/*   Updated: 2024/03/01 22:05:09 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lst2ndlast(t_list *lst)
{
	t_list	*tmp;

	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		tmp = lst;
		lst = lst->next;
	}
	return (tmp);
}

void	ft_pa(t_list *lst_a, t_list *lst_b)
{
	t_list	*node;

	node = lst_a;
	lst_a = lst_a->next;
	node->next = lst_b;
	lst_b = node;
}

void	ft_pb(t_list *lst_a, t_list *lst_b)
{
	t_list	*node;

	node = lst_b;
	lst_b = lst_b->next;
	node->next = lst_a;
	lst_a = node;
}

void	ft_sa(t_list *lst_a)
{
	t_list	*node;

	node = lst_a->next;
	lst_a->next = node->next;
	node->next = lst_a;
	lst_a = node;
}

void	ft_sb(t_list *lst_b)
{
	t_list	*node;

	node = lst_b->next;
	lst_b->next = node->next;
	node->next = lst_b;
	lst_b = node;
}

void	ft_ss(t_list *lst_a, t_list *lst_b)
{
	ft_sa(lst_a);
	ft_sb(lst_b);
}

void	ft_ra(t_list *lst_a)
{
	t_list	*tmp;

	tmp = lst_a->next;
	lst_a->next = NULL;
	ft_lstadd_back(&tmp, lst_a);
	lst_a = tmp;
}

void	ft_rb(t_list *lst_b)
{
	t_list	*tmp;

	tmp = lst_b->next;
	lst_b->next = NULL;
	ft_lstadd_back(&tmp, lst_b);
	lst_b = tmp;
}

void	ft_rr(t_list *lst_a, t_list *lst_b)
{
	ft_ra(lst_a);
	ft_rb(lst_b);
}

void	ft_rra(t_list *lst_a)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = ft_lstlast(lst_a);
	tmp2 = ft_lst2ndlast(lst_a);
	tmp2->next = NULL;
	ft_lstadd_front(&lst_a, tmp1);
}

void	ft_rrb(t_list *lst_b)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = ft_lstlast(lst_b);
	tmp2 = ft_lst2ndlast(lst_b);
	tmp2->next = NULL;
	ft_lstadd_front(&lst_b, tmp1);
}

void	ft_rrr(t_list *lst_a, t_list *lst_b)
{
	ft_rra(lst_a);
	ft_rrb(lst_b);
}

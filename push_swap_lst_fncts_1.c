/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lst_fncts_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:19:56 by maweiss           #+#    #+#             */
/*   Updated: 2024/04/07 15:47:34 by maweiss          ###   ########.fr       */
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

int	ft_pa(t_list **lst_a, t_list **lst_b, int silent)
{
	t_list	*node;

	if (*lst_b == NULL)
		return (1);
	node = *lst_b;
	*lst_b = (*lst_b)->next;
	node->next = *lst_a;
	*lst_a = node;
	if (silent != 1)
		ft_putstr_fd("pa\n", 1);
	return (0);
}

int	ft_pb(t_list **lst_a, t_list **lst_b, int silent)
{
	t_list	*node;

	if (*lst_a == NULL)
		return (1);
	node = *lst_a;
	*lst_a = (*lst_a)->next;
	node->next = *lst_b;
	*lst_b = node;
	if (silent != 1)
		ft_putstr_fd("pb\n", 1);
	return (0);
}

int	ft_sa(t_list **lst_a, int silent)
{
	t_list	*node;

	if (*lst_a == NULL || (*lst_a)->next == NULL)
		return (1);
	node = (*lst_a)->next;
	(*lst_a)->next = (*lst_a)->next->next;
	node->next = *lst_a;
	*lst_a = node;
	if (silent != 1)
		ft_putstr_fd("sa\n", 1);
	return (0);
}

int	ft_sb(t_list **lst_b, int silent)
{
	t_list	*node;

	if (*lst_b == NULL || (*lst_b)->next == NULL)
		return (1);
	node = (*lst_b)->next;
	(*lst_b)->next = (*lst_b)->next->next;
	node->next = *lst_b;
	*lst_b = node;
	if (silent != 1)
		ft_putstr_fd("sb\n", 1);
	return (0);
}

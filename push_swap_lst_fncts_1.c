/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lst_fncts_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wssmrks <wssmrks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:19:56 by maweiss           #+#    #+#             */
/*   Updated: 2024/03/18 20:45:40 by wssmrks          ###   ########.fr       */
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

void	ft_pa(t_list **lst_a, t_list **lst_b, int silent)
{
	t_list	*node;

	if (*lst_b == NULL)
	{
		ft_putstr_fd("Stack b is empty\n", 1);
		return ;
	}
	node = *lst_b;
	*lst_b = (*lst_b)->next;
	node->next = *lst_a;
	*lst_a = node;
	if (silent != 1)
		ft_putstr_fd("pa\n", 1);
}

void	ft_pb(t_list **lst_a, t_list **lst_b, int silent)
{
	t_list	*node;

	if (*lst_a == NULL)
	{
		ft_putstr_fd("Stack a is empty\n", 1);
		return ;
	}
	node = *lst_a;
	*lst_a = (*lst_a)->next;
	node->next = *lst_b;
	*lst_b = node;
	if (silent != 1)
		ft_putstr_fd("pb\n", 1);
}

void	ft_sa(t_list **lst_a, int silent)
{
	t_list	*node;

	if (*lst_a == NULL)
	{
		ft_putstr_fd("Stack a is empty\n", 1);
		return ;
	}
	node = (*lst_a)->next;
	(*lst_a)->next = (*lst_a)->next->next;
	node->next = *lst_a;
	*lst_a = node;
	if (silent != 1)
		ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_list **lst_b, int silent)
{
	t_list	*node;

	if (*lst_b == NULL)
	{
		ft_putstr_fd("Stack b is empty\n", 1);
		return ;
	}
	node = (*lst_b)->next;
	(*lst_b)->next = (*lst_b)->next->next;
	node->next = *lst_b;
	*lst_b = node;
	if (silent != 1)
		ft_putstr_fd("sb\n", 1);
}

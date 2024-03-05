/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_c.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:19:56 by maweiss           #+#    #+#             */
/*   Updated: 2024/03/05 15:19:11 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrb(t_list *lst_b, int silent)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (lst_b == NULL)
	{
		ft_putstr_fd("Stack b is empty\n", 1);
		return ;
	}
	tmp1 = ft_lstlast(lst_b);
	tmp2 = ft_lst2ndlast(lst_b);
	tmp2->next = NULL;
	ft_lstadd_front(&lst_b, tmp1);
	if (silent != 1)
		ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_list *lst_a, t_list *lst_b, int silent)
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
	ft_rra(lst_a, 1);
	ft_rrb(lst_b, 1);
	if (silent != 1)
		ft_putstr_fd("rrr\n", 1);
}

void	ft_free(void **tofree, int index)
{
	int	i;

	if (!tofree)
		return ;
	i = 0;
	if (index != 0)
	{
		while (i <= index)
		{
			free((void *)tofree[i]);
			i++;
		}
	}
	else
	{
		while (tofree[i])
		{
			free((void *)tofree[i]);
			i++;
		}
	}
	free((void *)tofree);
	return ;
}

void	ft_lstfree(t_list **lst)
{
	void	*del;

	del = &free;
	ft_lstclear(lst, del);
}

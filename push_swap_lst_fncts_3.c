/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lst_fncts_3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:19:56 by maweiss           #+#    #+#             */
/*   Updated: 2024/03/27 14:30:59 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rrb(t_list **lst_b, int silent)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (*lst_b == NULL)
		return (1);
	tmp1 = ft_lstlast(*lst_b);
	tmp2 = ft_lst2ndlast(*lst_b);
	tmp2->next = NULL;
	ft_lstadd_front(lst_b, tmp1);
	if (silent != 1)
		ft_putstr_fd("rrb\n", 1);
	return (0);
}

int	ft_rrr(t_list **lst_a, t_list **lst_b, int silent)
{
	if (*lst_b == NULL || *lst_a == NULL)
		return (1);
	ft_rra(lst_a, 1);
	ft_rrb(lst_b, 1);
	if (silent != 1)
		ft_putstr_fd("rrr\n", 1);
	return (0);
}

void	ft_lstfree(t_list **lst)
{
	void	*del;

	del = &free;
	ft_lstclear(lst, del);
}

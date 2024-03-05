/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:37:36 by maweiss           #+#    #+#             */
/*   Updated: 2024/03/05 16:02:18 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_dup_sorted(t_list *lst_a)
{
	int		value;
	int		ret;
	t_list	*tmp_a;
	t_list	*tmp_b;

	ret = 1;
	tmp_a = lst_a;
	value = INT_MIN;
	while (tmp_a)
	{
		tmp_b = tmp_a->next;
		if (value > *(int *)tmp_a->content && ret != -1)
			ret = 0;
		value = *(int *)tmp_a->content;
		while (tmp_b)
		{
			if (*(int *)tmp_a->content == *(int *)tmp_b->content)
				return (-1);
			tmp_b = tmp_b->next;
		}
		tmp_a = tmp_a->next;
	}
	return (ret);
}

int	ft_sorted(t_list *lst_a)
{
	long	value;
	int		ret;
	t_list	*tmp_a;
	t_list	*tmp_b;

	ret = 0;
	tmp_a = lst_a;
	value = -1 - INT_MIN;
	while (tmp_a)
	{
		tmp_b = tmp_a->next;
		if (value < *(long *)tmp_a->content && ret != -1)
			ret++;
		value = *(long *)tmp_a->content;
		tmp_a = tmp_a->next;
	}
	return (ret);
}

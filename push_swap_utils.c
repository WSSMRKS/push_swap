/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:19:56 by maweiss           #+#    #+#             */
/*   Updated: 2024/03/08 18:01:26 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_fill_lst(int **stack_a, int *size)
{
	t_list	*lst_a;
	int		i;
	int		sor_dup;

	i = 0;
	lst_a = ft_lstnew(stack_a[i]);
	stack_a[i++] = NULL;
	while (i < *size)
	{
		ft_lstadd_back(&lst_a, ft_lstnew(stack_a[i]));
		stack_a[i++] = NULL;
	}
	sor_dup = ft_dup_sorted(lst_a);
	if (sor_dup != 0)
	{
		if (sor_dup == -1)
			ft_putstr_fd("ERROR\n", 2);
		ft_lstfree(&lst_a);
		free(stack_a);
		exit(3);
	}
	else
		return (lst_a);
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

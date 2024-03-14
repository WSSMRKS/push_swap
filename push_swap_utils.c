/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:19:56 by maweiss           #+#    #+#             */
/*   Updated: 2024/03/14 13:17:18 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_fill_lst(int **stack_a, int *size)
{
	t_list	*lst_a;
	int		i;
	int		sor_dup;

	i = 0;
	lst_a = ft_lstnew(ft_create_content(stack_a[i++]));
	while (i < *size)
		ft_lstadd_back(&lst_a, ft_lstnew(ft_create_content(stack_a[i++])));
	sor_dup = ft_dup_sorted(lst_a);
	if (sor_dup != 0)
	{
		if (sor_dup == -1)
			ft_putstr_fd("ERROR\n", 2);
		ft_lstfree(&lst_a);
		ft_free((void **)stack_a, 0);
		exit(3);
	}
	else
		return (lst_a);
}

t_content	*ft_create_content(int *val)
{
	t_content	*l_obj;

	l_obj = malloc(sizeof(t_content));
	l_obj->value = *val;
	return (l_obj);
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
	int			value;
	int			ret;
	t_content	*tmp_a;
	t_content	*tmp_b;
	t_list		*tmp_l;

	ret = 1;
	tmp_a = lst_a->content;
	value = INT_MIN;
	while (lst_a)
	{
		tmp_a = lst_a->content;
		if (value > tmp_a->value && ret != -1)
			ret = 0;
		value = tmp_a->value;
		tmp_l = lst_a->next;
		while (tmp_l)
		{
			tmp_b = tmp_l->content;
			if (tmp_a->value == tmp_b->value)
				return (-1);
			tmp_l = tmp_l->next;
		}
		lst_a = lst_a->next;
	}
	return (ret);
}

// int	ft_sorted(t_list *lst_a)
// {
// 	long	value;
// 	int		ret;
// 	t_list	*tmp_a;
// 	t_list	*tmp_b;

// 	ret = 0;
// 	tmp_a = lst_a;
// 	value = -1 - INT_MIN;
// 	while (tmp_a)
// 	{
// 		tmp_b = tmp_a->next;
// 		if (value < *(long *)tmp_a->content && ret != -1)
// 			ret++;
// 		value = *(long *)tmp_a->content;
// 		tmp_a = tmp_a->next;
// 	}
// 	return (ret);
// }

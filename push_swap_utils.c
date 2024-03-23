/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wssmrks <wssmrks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:19:56 by maweiss           #+#    #+#             */
/*   Updated: 2024/03/23 21:27:48 by wssmrks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_fill_lst(int **stack_a, int *size)
{
	t_list	*lst_a;
	int		i;
	int		sor_dup;

	i = 0;
	lst_a = ft_lstnew(ft_create_cont(stack_a[i++]));
	while (i < *size)
		ft_lstadd_back(&lst_a, ft_lstnew(ft_create_cont(stack_a[i++])));
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

t_cont	*ft_create_cont(int *val)
{
	t_cont	*l_obj;

	l_obj = malloc(sizeof(t_cont));
	l_obj->value = *val;
	l_obj->index = 0;
	l_obj->chunk = 0;
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
	t_list		*tmp_a;
	t_list		*tmp_b;

	ret = 1;
	tmp_a = lst_a;
	value = INT_MIN;
	while (tmp_a)
	{
		if (value > tmp_a->cont->value && ret != -1)
			ret = 0;
		value = tmp_a->cont->value;
		tmp_b = tmp_a->next;
		while (tmp_b)
		{
			if (tmp_a->cont->value == tmp_b->cont->value)
				return (-1);
			tmp_b = tmp_b->next;
		}
		tmp_a = tmp_a->next;
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
// 		if (value < *(long *)tmp_a->cont && ret != -1)
// 			ret++;
// 		value = *(long *)tmp_a->cont;
// 		tmp_a = tmp_a->next;
// 	}
// 	return (ret);
// }

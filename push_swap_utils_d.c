/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_d.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:19:56 by maweiss           #+#    #+#             */
/*   Updated: 2024/03/05 14:46:11 by maweiss          ###   ########.fr       */
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

void	ft_switch(int **stack_a, int *size)
{
	char	purpose;

	purpose = PURPOSE_PS;
	if (purpose == 1)
		ft_solve(stack_a, size);
	else if (purpose == 2)
	{
		write(2, "Checker not implemented yet!\n", 29);
		ft_free((void **)stack_a, 0);
		exit(1);
	}
	else
	{
		write(2, "Invalid Value for \"PURPOSE_PS\"!\n", 32);
		ft_free((void **)stack_a, 0);
		exit(1);
	}
}

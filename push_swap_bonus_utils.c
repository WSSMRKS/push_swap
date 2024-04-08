/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:49:01 by maweiss           #+#    #+#             */
/*   Updated: 2024/04/08 19:39:22 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_ex_line(t_list **lst_a, t_list **lst_b, char *line)
{
	if (ft_strncmp(line, "sa\n", 4) == 0)
		return (ft_sa(lst_a, 1));
	else if (ft_strncmp(line, "sb\n", 4) == 0)
		return (ft_sb(lst_b, 1));
	else if (ft_strncmp(line, "ss\n", 4) == 0)
		return (ft_ss(lst_a, lst_b, 1));
	else if (ft_strncmp(line, "pb\n", 4) == 0)
		return (ft_pb(lst_a, lst_b, 1));
	else if (ft_strncmp(line, "pa\n", 4) == 0)
		return (ft_pa(lst_a, lst_b, 1));
	else if (ft_strncmp(line, "ra\n", 4) == 0)
		return (ft_ra(lst_a, 1));
	else if (ft_strncmp(line, "rb\n", 4) == 0)
		return (ft_rb(lst_b, 1));
	else if (ft_strncmp(line, "rr\n", 4) == 0)
		return (ft_rr(lst_a, lst_b, 1));
	else if (ft_strncmp(line, "rra\n", 5) == 0)
		return (ft_rra(lst_a, 1));
	else if (ft_strncmp(line, "rrb\n", 5) == 0)
		return (ft_rrb(lst_b, 1));
	else if (ft_strncmp(line, "rrr\n", 5) == 0)
		return (ft_rrr(lst_a, lst_b, 1));
	else
		return (2);
}

int	ft_loop_lines(char *line, t_list **lst_a, t_list **lst_b)
{
	int	res;

	res = 0;
	while (line)
	{
		res = ft_ex_line(lst_a, lst_b, line);
		if (res != 0)
		{
			if (line)
				free(line);
			return (res);
		}
		else
		{
			free(line);
			line = ft_get_next_line(0);
		}
	}
	return (0);
}

void	ft_checker(t_list **lst_a, t_list **lst_b, int *dup_sorted, int *res)
{
	char	*line;

	*dup_sorted = ft_dup_sorted(*lst_a);
	line = ft_get_next_line(0);
	if (*dup_sorted == -1 && line == NULL)
		ft_putstr_fd("Error\n", 2);
	else if (*dup_sorted == 1 && line == NULL)
		ft_printf("OK\n");
	else if (*dup_sorted == 0 && line == NULL)
		ft_printf("KO\n");
	else if (line)
	{
		*res = ft_loop_lines(line, lst_a, lst_b);
		if (*lst_a && ft_dup_sorted(*lst_a) == 1 && !*lst_b && *res == 0)
			ft_printf("OK\n");
		else if (*res == 2)
			ft_printf("Error\n");
		else if (*res == 1 || (*lst_a && ft_dup_sorted(*lst_a) != 1))
			ft_printf("KO\n");
	}
	if (lst_a)
		ft_lstfree(lst_a);
	if (lst_b)
		ft_lstfree(lst_b);
}

void	ft_check(int **stack_a, int *size)
{
	t_list	*lst_a;
	t_list	*lst_b;
	int		dup_sorted;
	int		res;

	res = 1;
	dup_sorted = 0;
	lst_a = NULL;
	lst_b = NULL;
	lst_a = ft_fill_lst(stack_a, size);
	ft_checker(&lst_a, &lst_b, &dup_sorted, &res);
	ft_free((void **)stack_a, 0);
	exit(1);
}

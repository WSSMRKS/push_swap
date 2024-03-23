/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wssmrks <wssmrks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:49:01 by maweiss           #+#    #+#             */
/*   Updated: 2024/03/24 00:06:23 by wssmrks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_switch(int **stack_a, int *size)
{
	ft_check(stack_a, size);
	exit(1);
}

int	ft_ex_line(t_list **lst_a, t_list **lst_b, char *line)
{
	if (ft_strncmp(line, "sa\n", 4) == 0)
		ft_sa(lst_a, 1);
	else if (ft_strncmp(line, "sb\n", 4) == 0)
		ft_sb(lst_b, 1);
	else if (ft_strncmp(line, "ss\n", 4) == 0)
		ft_ss(lst_a, lst_b, 1);
	else if (ft_strncmp(line, "pb\n", 4) == 0)
		ft_pb(lst_a, lst_b, 1);
	else if (ft_strncmp(line, "pa\n", 4) == 0)
		ft_pa(lst_a, lst_b, 1);
	else if (ft_strncmp(line, "ra\n", 4) == 0)
		ft_ra(lst_a, 1);
	else if (ft_strncmp(line, "rb\n", 4) == 0)
		ft_rb(lst_b, 1);
	else if (ft_strncmp(line, "rr\n", 4) == 0)
		ft_rr(lst_a, lst_b, 1);
	else if (ft_strncmp(line, "rra\n", 5) == 0)
		ft_rra(lst_a, 1);
	else if (ft_strncmp(line, "rrb\n", 5) == 0)
		ft_rrb(lst_b, 1);
	else if (ft_strncmp(line, "rrr\n", 5) == 0)
		ft_rrr(lst_a, lst_b, 1);
	else
		return (-1);
	return (1);
}

void	ft_loop_lines(char *line, t_list **lst_a, t_list **lst_b)
{
	while (line)
	{
		if (ft_ex_line(lst_a, lst_b, line) == -1)
		{
			ft_printf("KO! (instruction not known)\n");
			free(line);
			line = NULL;
			if (lst_a)
				ft_lstfree(lst_a);
			if (lst_b)
				ft_lstfree(lst_b);
		}
		else
		{
			free(line);
			line = ft_get_next_line(0);
		}
	}
}

void	ft_checker(t_list **lst_a, t_list **lst_b)
{
	char	*line;
	int		dup_sorted;

	dup_sorted = 0;
	dup_sorted = ft_dup_sorted(*lst_a);
	line = ft_get_next_line(0);
	if (dup_sorted == -1 && line == NULL)
		ft_printf("ERROR(DUPLICATE)!\n");
	else if (dup_sorted == 1 && line == NULL)
		ft_printf("OK(SORTED)!\n");
	else if (line)
		ft_loop_lines(line, lst_a, lst_b);
	if (ft_dup_sorted(*lst_a) == 1 && !*lst_b)
		ft_printf("OK(SORTED through instructions)!\n");
	else
		ft_printf("KO! Not sorted after execution\n");
	if (lst_a)
		ft_lstfree(lst_a);
	if (lst_b)
		ft_lstfree(lst_b);
}

void	ft_check(int **stack_a, int *size)
{
	t_list	*lst_a;
	t_list	*lst_b;

	lst_a = ft_fill_lst(stack_a, size);
	lst_b = NULL;
	ft_checker(&lst_a, &lst_b);
	ft_free((void **)stack_a, 0);
	exit(1);
}

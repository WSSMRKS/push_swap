/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:49:01 by maweiss           #+#    #+#             */
/*   Updated: 2024/03/08 16:16:28 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ex_inst(t_list *lst_a, t_list *lst_b, char *inst)
{
	if (ft_strncmp(inst, "sa\n", 4) == 0)
		ft_sa(lst_a, 1);
	else if (ft_strncmp(inst, "sb\n", 4) == 0)
		ft_sb(lst_b, 1);
	else if (ft_strncmp(inst, "ss\n", 4) == 0)
		ft_ss(lst_a, lst_b, 1);
	else if (ft_strncmp(inst, "pb\n", 4) == 0)
		ft_pb(lst_a, lst_b, 1);
	else if (ft_strncmp(inst, "pa\n", 4) == 0)
		ft_pa(lst_a, lst_b, 1);
	else if (ft_strncmp(inst, "ra\n", 4) == 0)
		ft_ra(lst_a, 1);
	else if (ft_strncmp(inst, "rb\n", 4) == 0)
		ft_rb(lst_b, 1);
	else if (ft_strncmp(inst, "rr\n", 4) == 0)
		ft_rr(lst_a, lst_b, 1);
	else if (ft_strncmp(inst, "rra\n", 5) == 0)
		ft_rra(lst_a, 1);
	else if (ft_strncmp(inst, "rrb\n", 5) == 0)
		ft_rrb(lst_b, 1);
	else if (ft_strncmp(inst, "rrr\n", 5) == 0)
		ft_rrr(lst_a, lst_b, 1);
	else
		return (-1);
	return (1);
}

void	ft_read_inst(t_list *lst_a, t_list *lst_b)
{
	char	*inst;

	*inst = ft_get_next_line(0);
	if (ft_ex_inst(lst_a, lst_b, inst) == -1)
		//do something on error.
	else
		free(inst);
}

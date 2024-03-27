/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_utils_3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:37:36 by maweiss           #+#    #+#             */
/*   Updated: 2024/03/27 17:54:45 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_0_top(t_list **lst_a)
{
	int	dist;

	dist = ft_find_index(lst_a, 0);
	while (dist != 0)
	{
		if (dist < 0)
		{
			ft_rra(lst_a, 0);
			dist++;
		}
		else
		{
			ft_ra(lst_a, 0);
			dist--;
		}
	}
}

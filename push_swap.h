/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:20:36 by maweiss           #+#    #+#             */
/*   Updated: 2024/03/14 13:21:37 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdio.h>
# include <limits.h>
# include <stddef.h>

typedef struct s_content
{
	int	value;
	int	index;
	int	pivot;
	int	distance;
}			t_content;

t_list		*ft_lst2ndlast(t_list *lst);
void		ft_pa(t_list **lst_a, t_list **lst_b, int silent);
void		ft_pb(t_list **lst_a, t_list **lst_b, int silent);
void		ft_sa(t_list **lst_a, int silent);
void		ft_sb(t_list **lst_b, int silent);
void		ft_ss(t_list **lst_a, t_list **lst_b, int silent);
void		ft_ra(t_list **lst_a, int silent);
void		ft_rb(t_list **lst_b, int silent);
void		ft_rr(t_list **lst_a, t_list **lst_b, int silent);
void		ft_rra(t_list **lst_a, int silent);
void		ft_rrb(t_list **lst_b, int silent);
void		ft_rrr(t_list **lst_a, t_list **lst_b, int silent);
void		ft_free(void **tofree, int index);
void		ft_lstfree(t_list **lst);
int			ft_dup_sorted(t_list *lst_a);
// int			ft_sorted(t_list *lst_a);
t_list		*ft_fill_lst(int **stack_a, int *size);
void		ft_solve(int **stack_a, int *size);
void		ft_solve_3(t_list **lst_a);
void		ft_solve_5(t_list **lst_a, t_list **lst_b, int *size);
void		ft_solve_10(t_list **lst_a, t_list **lst_b, int *size);
void		ft_solve_big(t_list **lst_a, t_list **lst_b, int *size);
void		ft_switch(int **stack_a, int *size);
t_content	*ft_create_content(int *val);

#endif

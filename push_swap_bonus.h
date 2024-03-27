/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:20:36 by maweiss           #+#    #+#             */
/*   Updated: 2024/03/27 15:36:16 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stddef.h>
# include "push_swap.h"

int		ft_ex_line(t_list **lst_a, t_list **lst_b, char *line);
int		ft_loop_lines(char *line, t_list **lst_a, t_list **lst_b);
void	ft_checker(t_list **lst_a, t_list **lst_b, int error);
void	ft_check(int **stack_a, int *size, int error);

#endif

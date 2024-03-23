/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wssmrks <wssmrks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:20:36 by maweiss           #+#    #+#             */
/*   Updated: 2024/03/24 00:03:23 by wssmrks          ###   ########.fr       */
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
void	ft_loop_lines(char *line, t_list **lst_a, t_list **lst_b);
void	ft_checker(t_list **lst_a, t_list **lst_b);
void	ft_check(int **stack_a, int *size);

#endif

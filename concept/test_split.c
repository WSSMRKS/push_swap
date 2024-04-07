/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 12:37:56 by maweiss           #+#    #+#             */
/*   Updated: 2024/04/07 13:06:21 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static void	ft_free(char **tofree)
// {
// 	int	i;

// 	if (!tofree)
// 		return ;
// 	i = 0;
// 	while (tofree[i])
// 	{
// 		free((void *)tofree[i]);
// 		i++;
// 	}
// 	free((void *)tofree);
// 	return ;
// }

int	main(void)
{
	char	*split_this = "  ";
	// int		i = 0;
	char	**split;

	split = ft_split(split_this, ' ');
	ft_printf("%s", split [0]);

	// while (i < 1)
	// {
	// 	ft_putstr_non_printable(split[i], 20);
	// 	//ft_printf("%s", split[i++]);
	// }
	// ft_free(split);
}

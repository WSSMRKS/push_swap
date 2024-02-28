/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:49:01 by maweiss           #+#    #+#             */
/*   Updated: 2024/02/28 11:17:23 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <libft/libft.h>
#include <limits.h>
#include <stddef.h>

static void	ft_free(char **tofree)
{
	int	i;

	if (!tofree)
		return ;
	i = 0;
	while (tofree[i])
	{
		free((void *)tofree[i]);
		i++;
	}
	free((void *)tofree);
	return ;
}

int	ft_validate_args(char *str, int *valid)
{
	int		i;
	long	nbr;

	nbr = 0;
	i = 0;
	*valid = 1;
	if (!str)
		return (NULL);
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			break ;
	}
	if (str[i] == '\0' && i <= 11 && ((nbr = ft_atol(str))) >= -2147483648
		&& nbr <= 2147483647)
		return ((int) nbr);
	else
		*valid = 0;
	return (0);
}

char	*ft_parse_several(int argc, char **argv)
{
	int			count;
	int			*stack_a;
	short int	a;

	count = 1;
	while (count++ <= argc)
		ft_fill_stack(ft_atol(ft_validate_args(argv[count])),
			stack_a[count - 1]);
	return (stack_a);
}

char	*ft_validate_str(char *str, int mode)
{
	int	i;

	while (str[i] && (str[i] != ' ' || str[i] != '\t' || str[i] != '\v'
			|| str[i] != '\r' || str[i] != '\n' || str[i] != '\f'))
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			break ;
	}
	if (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\r'
		|| str[i] == '\n' || str[i] == '\f' || str[i] == '\0')
		return (str);
	else
		return (NULL);
}

int	ft_parse_one(char *input)
{
	char	**split;
	int		*stack_a;
	int		i;
	long	nbr;
	int		valid;

	i = ft_countwords(input, ' ');
	stack_a = (int *) malloc(sizeof(int) * i);
	split = ft_split(*input, ' ');
	if (!split)
		return (0);
	i = 0;
	while (split[i])
	{
		stack_a[i] = ft_atol(ft_validate_args(split[i], &valid));
		if (valid != 1)
		{
			ft_free(split);
			return (0);
		}
		free(split[i]);
		i++;
	}
	free(split);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(2, "ERROR\n", 6);
		exit(1);
	}
	if (argc == 2)
		ft_parse_one(argv[1]);
	if (argc > 2)
		ft_parse_several(argc, **argv);
	return (1);
}

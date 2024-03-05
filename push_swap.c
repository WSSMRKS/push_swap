/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:49:01 by maweiss           #+#    #+#             */
/*   Updated: 2024/03/05 16:03:04 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_validate_args(char *str, int *valid)
{
	int		i;
	long	nbr;

	nbr = 0;
	i = 0;
	*valid = 1;
	if (!str)
		*valid = 0;
	if (*valid != 0 && str[i] == '-')
		i++;
	while (*valid != 0 && str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			*valid = 0;
	}
	if (valid != 0)
		nbr = ft_atol(str);
	if (valid != 0 && str[i] == '\0' && i <= 11 && nbr >= -2147483648
		&& nbr <= 2147483647)
		return ((int) nbr);
	else
		return (*valid = 0);
}

int	**ft_parse_several(int argc, char **argv)
{
	int			i;
	int			**stack_a;
	int			valid;

	stack_a = malloc(sizeof(int *) * (argc));
	if (!stack_a)
		return (NULL);
	i = 0;
	stack_a[argc - 1] = NULL;
	while (i < (argc - 1))
	{
		stack_a[i] = malloc(sizeof(int));
		*stack_a[i] = ft_validate_args(argv[i + 1], &valid);
		i++;
		if (valid != 1)
		{
			ft_free((void **)stack_a, 0);
			return (NULL);
		}
	}
	return (stack_a);
}

int	**ft_parse_one(char *input, int *size)
{
	char	**split;
	int		**stack_a;
	int		valid;

	stack_a = malloc(sizeof(int *) * (ft_countwords(input, ' ') + 1));
	if (!stack_a)
		return (NULL);
	split = ft_split(input, ' ');
	if (!split)
		return (NULL);
	while (split[*size])
	{
		stack_a[*size] = malloc(sizeof(int));
		*stack_a[*size] = ft_validate_args(split[*size], &valid);
		if (valid != 1)
		{
			ft_free((void **)split, 0);
			ft_free((void **)stack_a, *size);
			return (NULL);
		}
		(*size)++;
	}
	ft_free((void **)split, 0);
	stack_a[*size] = NULL;
	return (stack_a);
}

int	main(int argc, char **argv)
{
	int		**stack_a;
	int		size;

	if (argc < 2)
	{
		ft_putstr_fd("ERROR\n", 2);
		exit(1);
	}
	else if (argc == 2)
	{
		size = 0;
		stack_a = ft_parse_one(argv[1], &size);
	}
	else
	{
		stack_a = ft_parse_several(argc, argv);
		size = argc - 1;
	}
	if (!stack_a)
	{
		ft_putstr_fd("ERROR\n", 2);
		exit(2);
	}
	ft_switch(stack_a, &size);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:49:01 by maweiss           #+#    #+#             */
/*   Updated: 2024/02/28 13:01:01 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <libft/libft.h>
#include <limits.h>
#include <stddef.h>

void	ft_fill_lst(int *stack_a, int size)
{
	t_list	**lst_a;
	int		i;

	while(stack_a[i])
	{
		ft_lstadd_front(lst_a, ft_lstnew(stack_a[i++]));
	}
	ft_init_ll(stack_a, size);
	ft_sort()
}

void	ft_switch(int *stack_a, int size, char purpose)
{
	if (purpose == 's')
		ft_solve(stack_a, size);
	else if (purpose == 'c')
		ft_check(stack_a, size);
}

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
	nbr = ft_atol(str);
	if (str[i] == '\0' && i <= 11 && nbr >= -2147483648
		&& nbr <= 2147483647)
		return ((int) nbr);
	else
		*valid = 0;
	return (0);
}

char	*ft_parse_several(int argc, char **argv)
{
	int			i;
	int			*stack_a;
	int			valid;

	stack_a = (int *) malloc(sizeof(int) * (argc - 1));
	i = 0;
	while (i <= (argc - 1))
	{
		stack_a[i++] = ft_atol(ft_validate_args(argv[i + 1], &valid)); // [ ] check if syntax is right (++)
		if (valid != 1)
		{
			free(stack_a);
			return (NULL);
		}
	}
	return (stack_a);1
}

char	*ft_parse_one(char *input, int *size)
{
	char	**split;
	int		*stack_a;
	int		i;
	int		valid;

	i = ft_countwords(input, ' ');
	stack_a = (int *) malloc(sizeof(int) * i);
	split = ft_split(*input, ' ');
	if (!split)
		return (NULL);
	i = 0;
	while (split[i])
	{
		stack_a[i] = ft_atol(ft_validate_args(split[i], &valid));
		if (valid != 1)
		{
			ft_free(split);
			free(stack_a);
			return (NULL);
		}
		free(split[i++]);
	}
	free(split);
	*size = i; // [ ] validate right size from i
	return (stack_a);
}

int	main(int argc, char **argv)
{
	int		*stack_a;
	int		size;
	char	purpose;
	int		success;

	purpose = 's'; // [ ] s = solve; c = check;
	if (argc < 2)
	{
		write(2, "ERROR\n", 6);
		exit(1);
	}
	else if (argc == 2)
		stack_a = ft_parse_one(argv[1], &size);
	else
	{
		stack_a = ft_parse_several(argc, **argv);
		size = argc - 1;
	}
	if (!stack_a)
	{
		write(2, "ERROR\n", 6);
		exit(2);
	}
	ft_switch(stack_a, size, purpose);
	return (1);
}

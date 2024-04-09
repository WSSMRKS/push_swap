/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:49:01 by maweiss           #+#    #+#             */
/*   Updated: 2024/04/09 15:38:42 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (stack_a[i] == NULL)
			ft_free((void **)stack_a, 0);
		if (stack_a[i] == NULL)
			return (NULL);
		*stack_a[i] = ft_validate_args(argv[i + 1], &valid);
		i++;
		if (valid != 1)
		{
			ft_free((void **)stack_a, i);
			return (NULL);
		}
	}
	return (stack_a);
}

int	ft_protect(char **split, int **stack_a)
{
	if (!split || !split[0])
	{
		free(stack_a);
		if (split)
			free(split);
		return (-1);
	}
	return (1);
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
	if (ft_protect(split, stack_a) == -1)
		return (NULL);
	while (split[*size] != NULL)
	{
		stack_a[*size] = malloc(sizeof(int));
		if (stack_a[*size] != NULL)
			*stack_a[*size] = ft_validate_args(split[*size], &valid);
		if (stack_a[(*size)++] == NULL || valid != 1)
		{
			ft_free((void **)split, 0);
			ft_free((void **)stack_a, *size);
			return (NULL);
		}
	}
	ft_free((void **)split, 0);
	stack_a[*size] = NULL;
	return (stack_a);
}

t_list	*ft_fill_lst(int **stack_a, int *size)
{
	t_list	*lst_a;
	int		i;
	int		sor_dup;

	i = 0;
	lst_a = ft_lstnew(ft_create_cont(stack_a[i++]));
	while (i < *size)
		ft_lstadd_back(&lst_a, ft_lstnew(ft_create_cont(stack_a[i++])));
	sor_dup = ft_dup_sorted(lst_a);
	if (sor_dup != 0)
	{
		if (sor_dup == -1)
			ft_putstr_fd("Error\n", 2);
		ft_lstfree(&lst_a);
		ft_free((void **)stack_a, 0);
		exit(3);
	}
	else
		return (lst_a);
}

int	main(int argc, char **argv)
{
	int		**stack_a;
	int		size;
	int		error;

	size = 0;
	error = 0;
	if (argc < 2)
		exit(1);
	else if (argc == 2 && argv[1][0] != '\0')
		stack_a = ft_parse_one(argv[1], &size);
	else if (argv[1][0] != '\0')
	{
		stack_a = ft_parse_several(argc, argv);
		size = argc - 1;
	}
	if (argv[1][0] == '\0' || stack_a == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		exit(2);
	}
	ft_solve(stack_a, &size);
	return (0);
}

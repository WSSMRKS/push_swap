/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:49:01 by maweiss           #+#    #+#             */
/*   Updated: 2024/02/29 13:01:26 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstfree(t_list **lst)
{
	void	*del;

	del = &free;
	ft_lstclear(lst, del);
}

int	ft_sorted(t_list *lst_a)
{
	int		value;
	int		sorted;
	t_list	*tmp_l;

	tmp_l = lst_a;
	value = INT_MIN;
	sorted = 1;
	while (sorted == 1)
	{
		if (value <= *(int *)tmp_l->content)
		{
			sorted = 1;
			value = *(int *)tmp_l->content;
			if (tmp_l->next == NULL)
				break ;
			tmp_l = tmp_l->next;
		}
		else
			sorted = 0;
	}
	return (sorted);
}

t_list	*ft_fill_lst(int **stack_a, int *size)
{
	t_list	*lst_a;
	int		i;

	i = 0;
	lst_a = ft_lstnew(stack_a[i]);
	stack_a[i++] = NULL;
	while (i < *size)
	{
		ft_lstadd_back(&lst_a, ft_lstnew(stack_a[i]));
		stack_a[i++] = NULL;
	}
	if (ft_sorted(lst_a))
	{
		ft_lstfree(&lst_a);
		free(stack_a);
		exit(3);
	}
	else
		return (lst_a);
}

void	ft_solve(int **stack_a, int *size)
{
	t_list	*lst_a;

	lst_a = ft_fill_lst(stack_a, size);
}

void	ft_switch(int **stack_a, char purpose, int *size)
{
	if (purpose == 's')
		ft_solve(stack_a, size);
	else if (purpose == 'c')
		exit(1);
	//ft_check(stack_a);
}

static void	ft_free(void **tofree)
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
	{
		*valid = 0;
		return (0);
	}
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

int	**ft_parse_several(int argc, char **argv)
{
	int			i;
	int			**stack_a;
	int			valid;

	stack_a = malloc(sizeof(int *) * (argc));
	i = 0;
	while (i <= (argc - 1))
	{
		stack_a[i] = malloc(sizeof(int));
		*stack_a[i] = ft_validate_args(argv[i + 1], &valid); // [ ] check if syntax is right (++)
		i++;
		if (valid != 1)
		{
			free(stack_a);
			return (NULL);
		}
	}
	return (stack_a);
}

int	**ft_parse_one(char *input, int *size)
{
	char	**split;
	int		**stack_a;
	int		i;
	int		valid;

	i = ft_countwords(input, ' ');
	stack_a = malloc(sizeof(int *) * i + 1);
	split = ft_split(input, ' ');
	if (!split)
		return (NULL);
	i = 0;
	while (split[i])
	{
		stack_a[i] = malloc(sizeof(int));
		*stack_a[i] = ft_validate_args(split[i], &valid);
		if (valid != 1)
		{
			ft_free((void **)split);
			ft_free((void **)stack_a);
			return (NULL);
		}
		free(split[i++]);
	}
	stack_a[i] = NULL;
	free(split);
	*size = i; // [ ] validate right size from i
	return (stack_a);
}

int	main(int argc, char **argv)
{
	int		**stack_a;
	int		size;
	char	purpose;

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
		stack_a = ft_parse_several(argc, argv);
		size = argc - 1;
	}
	if (!stack_a)
	{
		write(2, "ERROR\n", 6);
		exit(2);
	}
	ft_switch(stack_a, purpose, &size);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:19:56 by maweiss           #+#    #+#             */
/*   Updated: 2024/04/08 16:54:47 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cont	*ft_create_cont(int *val)
{
	t_cont	*l_obj;

	l_obj = malloc(sizeof(t_cont));
	if (l_obj == NULL)
		return (NULL);
	l_obj->value = *val;
	l_obj->index = 0;
	l_obj->chunk = 0;
	return (l_obj);
}

void	ft_free(void **tofree, int index)
{
	int	i;

	if (!tofree)
		return ;
	i = 0;
	if (index != 0)
	{
		while (i < index)
		{
			free((void *)tofree[i]);
			i++;
		}
	}
	else
	{
		while (tofree[i])
		{
			free((void *)tofree[i]);
			i++;
		}
	}
	free((void *)tofree);
	return ;
}

int	ft_dup_sorted(t_list *lst_a)
{
	int			value;
	int			ret;
	t_list		*tmp_a;
	t_list		*tmp_b;

	ret = 1;
	tmp_a = lst_a;
	value = INT_MIN;
	while (tmp_a)
	{
		if (value > tmp_a->cont->value && ret != -1)
			ret = 0;
		value = tmp_a->cont->value;
		tmp_b = tmp_a->next;
		while (tmp_b)
		{
			if (tmp_a->cont->value == tmp_b->cont->value)
				return (-1);
			tmp_b = tmp_b->next;
		}
		tmp_a = tmp_a->next;
	}
	return (ret);
}

int	ft_validate_args(char *str, int *valid)
{
	int		i;
	long	nbr;

	nbr = 0;
	i = 0;
	*valid = 1;
	if (!str || (str[i] == '-' && str[i + 1] == '\0'))
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

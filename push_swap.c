/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:49:01 by maweiss           #+#    #+#             */
/*   Updated: 2024/02/27 16:09:21 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft/libft.h>

char	*ft_validate_args(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			break;
	}
	if (str[i] == '\0')
		return (str);
	else
		return (NULL);
}

char *ft_validate_str(char *str, int mode)
{
	while ((mode <= 2  && str[i] && (str[i] != ' ' || str[i] != '\t' || str[i] != '\v' || str[i] != '\r'
		|| str[i] != '\n' || str[i] != '\f') || mode > 2 && str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			break;
	}
	if (mode <= 2 && (str[i] != ' ' || str[i] != '\t' || str[i] != '\v' || str[i] != '\r'
		|| str[i] != '\n' || str[i] != '\f')
}

char	*ft_parse_several(int argc, char **argv)
{
	int	count;
	int	*stack_a;

	count = 1;
	while (count++ <= argc)
		ft_fill_stack(ft_atol(ft_validate(argv[count])), stack_a[count - 1]);
	return (stack_a);
}

int	ft_parse_one (char *input)
{
	int	len;
	int	count;
	int	*stack_a;

	while (*input)
	{
		if (*input >= '0' && *input<= '9')
		{
			len++;
		}
		else if (*input == ' ')
		{
			ft_extract_nr(input - len, len, *stack_a);
			len = 0;
			count++;
		}
		else
			write(2, "ERROR\n", 6);
			exit(2);
	}
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

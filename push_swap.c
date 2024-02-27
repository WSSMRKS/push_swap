/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:49:01 by maweiss           #+#    #+#             */
/*   Updated: 2024/02/27 15:03:10 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft/libft.h>

int	ft_parse_several(int argc, char **argv)
{
	int	count;
	int	*stack_a;

	count = 0;
	while(count++ < argc - 1)
		ft_fill_stack(ft_atoargv[count], stack_a);


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

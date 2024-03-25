/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:34:20 by maweiss           #+#    #+#             */
/*   Updated: 2024/02/27 21:02:04 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <stddef.h>

int	main(void)
{
	printf("{%d}, {%i}, {%u}, {%ld}, {%li}, {%lu}\n", INT_MAX);
	printf("{%d}, {%i}, {%u}, {%ld}, {%li}, {%lu}\n", INT_MIN);
	printf("{%d}, {%i}, {%u}, {%ld}, {%li}, {%lu}\n", LONG_MAX);
	printf("{%d}, {%i}, {%u}, {%ld}, {%li}, {%lu}\n", LONG_MIN);
	printf("{%d}, {%i}, {%u}, {%ld}, {%li}, {%lu}\n", __LONG_LONG_MAX__);
	printf("{%d}, {%i}, {%u}, {%ld}, {%li}, {%lu}\n", -__LONG_LONG_MAX__ - 1);
	printf("{%d}, {%i}, {%u}, {%ld}, {%li}, {%lu}\n", UINT_MAX);
	printf("{%d}, {%i}, {%u}, {%ld}, {%li}, {%lu}\n", ULONG_MAX);
	printf("{%d}, {%i}, {%u}, {%ld}, {%li}, {%lu}\n", ULLONG_MAX);
	printf("sizeof(int): %zu\n", sizeof(int));
	printf("sizeof(long): %zu\n", sizeof(long));
	printf("sizeof(long int): %zu\n", sizeof(long int));
	printf("sizeof(long long): %zu\n", sizeof(long long));
	printf("sizeof(long long int): %zu\n", sizeof(long long int));
	printf("sizeof(short int): %zu\n", sizeof(short int));
	printf("sizeof(long double): %zu\n", sizeof(long double));
	printf("sizeof(char): %zu\n", sizeof(char));
	printf("sizeof(short): %zu\n", sizeof(short));
	printf("sizeof(double): %zu\n", sizeof(double));
}

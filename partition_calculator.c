/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_calculator.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakurad <msakurad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:39:11 by msakurad          #+#    #+#             */
/*   Updated: 2023/09/26 18:01:35 by msakurad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	long long int	bytes;
	long int	mb_size;
	long int	gb_size;

	if (argc < 2)
	{
		printf("Check the arguments sent in the execution of the program\n");
		return (1);
	}
	if (argv[1])
	{
		mb_size = atol(argv[1]);
		bytes = mb_size * 1024 * 1024;
		printf("You want to convert %ldMB to %lld bytes\n", mb_size, bytes);
	}
	if (argv[2])
	{
		gb_size = atol(argv[2]);
		bytes = gb_size * 1024 * 1024 * 1024;
		printf("You want to convert %ldGB to %lld bytes\n", gb_size, bytes);
	}
	return (0);
}
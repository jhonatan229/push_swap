/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:46:46 by jestevam          #+#    #+#             */
/*   Updated: 2021/09/08 23:06:37 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static int verify_number(int add, int *list)
{
	int count = 0;
	while (list[count])
	{
		if (list[count] == add)
		{
			printf("number cloned!!\n");
			exit(2);
		}
		count++;
	}
	return (add);
}

int main(int argc, char **argv)
{
	int numbers[argc - 1];
	int n;

	n = 0;
	while (n + 1< argc)
	{
		numbers[n] = verify_number(atoi(argv[n + 1]), numbers);
		n++;
	}
	n = 0;
	while (n + 1< argc)
	{
		printf("n %i: %i\n", n, numbers[n]);
		n++;
	}
	return (0);
}
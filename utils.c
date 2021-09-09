/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 23:17:20 by jestevam          #+#    #+#             */
/*   Updated: 2021/09/09 17:22:16 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	verify_number(int add, t_lists *list)
{
	int count = 0;
	while (list->list_a[count])
	{
		if (list->list_a[count] == add)
		{
			free(list->list_a);
			free(list->list_b);
			exit(2);
		}
		count++;
	}
	return (add);
}

int ft_isdigit(char *str, t_lists *list)
{
	int count;

	count = 0;
	while (str[count] != 0)
	{
		if (str[count] < 48 || str[count] > 57)
		{
			free(list->list_a);
			free(list->list_b);
			exit(1);
		}
		count++;
	}
	return (0);
}

int static	ft_addnum(int *num, char c)
{
	if (c >= '0' && c <= '9')
	{
		if (*num != 0)
			*num *= 10;
		*num += c - '0';
		return (0);
	}
	return (1);
}

int	ft_atoi(const char *nptr, t_lists *list)
{
	int	sinal;
	int	num;

	num = 0;
	sinal = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sinal = -1;
		nptr++;
	}
	while (ft_addnum(&num, *nptr) == 0)
		nptr++;
	if (num * sinal < -2147483648 || num * sinal > 2147483647)
	{
		free(list->list_a);
		free(list->list_b);
		exit(1);
	}
	return (num * sinal);
}
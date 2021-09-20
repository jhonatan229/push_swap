/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 23:17:20 by jestevam          #+#    #+#             */
/*   Updated: 2021/09/20 12:58:21 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

//Will free the two list that use malloc.
//If the signal is different of 0, will print on terminal 'Error'.
void	free_lst_exit(t_lists *list, int signal)
{
	if (signal)
		write(2, "Error\n", 6);
	free(list->list_a);
	free(list->list_b);
	exit(1);
}

//Verify if the number that will be insert on list already is into the list. 
//If is true, the program exits.
int	verify_number(int add, t_lists *list, int limit)
{
	int	count;

	count = 0;
	while (count < limit)
	{
		if (list->list_a[count] == add)
			free_lst_exit(list, 1);
		count++;
	}
	return (add);
}

//Verify if the string str is a number.
//Exit of the program if isn't.
int	ft_isdigit(char *str, t_lists *list)
{
	int	count;

	count = 0;
	if (str[count] == '-')
		count++;
	while (str[count] != 0)
	{
		if (str[count] < 48 || str[count] > 57)
			free_lst_exit(list, 1);
		count++;
	}
	return (0);
}

static int	ft_addnum(long *num, char c)
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

//transform the string nptr in a number.
//if the number is bigger than max int and less than min int, the program should exit.
int	ft_atoi(const char *nptr, t_lists *list)
{
	int		sinal;
	long	num;

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
		free_lst_exit(list, 1);
	return (num * sinal);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_order_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:56:04 by jestevam          #+#    #+#             */
/*   Updated: 2021/09/13 22:24:17 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	rotate_list(int *lst, int size)
{
	int aux;

	if (size < 2)
		return ;
	size--;
	aux = lst[size];
	while (size != 0)
	{
		lst[size] = lst[size - 1];
		size--;
	}
	lst[size] = aux;
	write(1, "r\n", 2);
}

void	reverse_rotate_list(int *lst, int size)
{	
	int aux;
	int	count;

	if (size < 2)
		return ;	
	count = 0;
	aux = lst[count];
	while (count < size - 1)
	{
		lst[count] = lst[count + 1];
		count++;
	}
	lst[count] = aux;
	write(1, "rr\n", 3);
}

void	push_num_to_lst(t_lists *list, int signal)
{
	if (signal == 1)
	{
		if (!list->size_b)
		{
			printf("b is empty\n");
			return ;
		}
		list->list_a[list->size_a] = list->list_b[list->size_b - 1];
		list->size_b--;
		list->size_a++;
		write(1, "pa\n", 3);
	}
	else
	{
		if (!list->size_a)
		{
			printf("a is empty\n");
			return ;
		}
		list->list_b[list->size_b] = list->list_a[list->size_a - 1];
		list->size_a--;
		list->size_b++;
		write(1, "pb\n", 3);
	}
}

void	swap(int *lst, int size)
{
	int aux;
	
	if (size < 2)
		return ;
	aux = lst[size - 1];
	lst[size - 1] = lst[size - 2];
	lst[size - 2] = aux;
}

int	verify_sort_list(int *lst, int size, int signal)
{
	int count;

	count = 0;
	if (size < 2)
		return (0);
	if (signal == 1)
	{
		while (--size != 0)
		{
			if (lst[size] > lst[size - 1])
				return (1);
		}
	}
	else
	{
		while (count < size - 1)
			if (lst[count] > lst[count + 1])
				return (1);
	}
	return (0);
}
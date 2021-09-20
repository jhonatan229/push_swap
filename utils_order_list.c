/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_order_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:56:04 by jestevam          #+#    #+#             */
/*   Updated: 2021/09/20 13:17:23 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

//take the last number of the list and put at the beginning
//use signal as 1 to print ra(rotate list a);
//and signal as 2 to print rb(rotate list b);
void	rotate_list(int *lst, int size, int signal)
{
	int	aux;

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
	if (signal == 1)
		write(1, "ra\n", 3);
	else if (signal == 2)
		write(1, "rb\n", 3);
}

//take the first number at the list and put at the end
//use signal as 1 to print rra(reverse rotate list a);
//and signal as 2 to print rrb(reverse rotate list b);
void	reverse_rotate_list(int *lst, int size, int signal)
{	
	int	aux;
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
	if (signal == 1)
		write(1, "rra\n", 4);
	else if (signal == 2)
		write(1, "rrb\n", 4);
}

//Put the last number on a list to the end of a another list.
//use the signal as 1 to put the number in list b to list a;
//use the signal as 2 to put the number in list a to list b;
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

//swap the last two numbers of the list;
//use the signal to print sa (if is list a);
//use the signal to print sb (is is list b);
void	swap(int *lst, int size, int signal)
{
	int	aux;

	if (size < 2)
		return ;
	aux = lst[size - 1];
	lst[size - 1] = lst[size - 2];
	lst[size - 2] = aux;
	if (signal == 1)
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

//verify is list is sort;
//use the signal as 1 if you want verify list a;
//use the signal as 2 if you want verify list b;
int	verify_sort_list(int *lst, int size, int signal)
{
	int	count;

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

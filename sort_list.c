/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 15:44:08 by jestevam          #+#    #+#             */
/*   Updated: 2021/09/16 16:09:33 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	find_max_chunck(t_lists *lst, int *last, int chunck)
{
	int	num;
	int	count;

	count = 0;
	num = 2147483647;
	while (count < lst->size_a)
	{
		if (lst->list_a[count] < num && lst->list_a[count] > *last)
			num = lst->list_a[count];
		count++;
	}
	chunck++;
	*last = num;
	if (chunck == 25 || num == 2147483647)
		return (chunck);
	else
		chunck = find_max_chunck(lst, last, chunck);
	return (chunck);
}

static int	check_top_b(int *lst, int size, int num)
{
	int	dif;
	int	pos;
	int	count;

	count = 0;
	dif = 2147483647;
	pos = 0;
	while (count < size)
	{
		if (num - lst[count] < dif && lst[count] < num)
		{
			dif = num - lst[count];
			pos = count;
		}
		count++;
	}
	if (dif == 2147483647)
		pos = check_top_b(lst, size, 2147483647);
	return (pos);
}

void	push_number(t_lists *lst, int pos)
{
	int	pos_b;
	int	top_a;

	verify_pos_to_push(lst->list_a, lst->size_a, pos, 1);
	if (!lst->size_b)
		push_num_to_lst(lst, 0);
	else
	{
		top_a = lst->list_a[lst->size_a - 1];
		pos_b = check_top_b(lst->list_b, lst->size_b, top_a);
		verify_pos_to_push(lst->list_b, lst->size_b, pos_b, 2);
		push_num_to_lst(lst, 0);
	}
}

void	return_b_to_a(t_lists *lst)
{
	int	count;
	int	pos;
	int	num;

	num = -2147483648;
	count = 0;
	while (count < lst->size_b)
	{
		if (lst->list_b[count] > num)
		{
			num = lst->list_b[count];
			pos = count;
		}
		count++;
	}
	verify_pos_to_push(lst->list_b, lst->size_b, pos, 2);
	while (lst->size_b)
		push_num_to_lst(lst, 1);
}

void	push_more_close(t_lists *lst, int chunck)
{
	int	count;
	int	dif;
	int	pos;

	pos = 0;
	dif = 2147483647;
	count = 0;
	while (count < lst->size_a)
	{
		if (lst->list_a[count] < chunck)
		{
			if (count < dif)
			{
				pos = count;
				dif = count;
			}
			else if (lst->size_a - count < dif)
			{
				pos = count;
				dif = lst->size_a - count;
			}
		}
		count++;
	}
	push_number(lst, pos);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 10:21:28 by jestevam          #+#    #+#             */
/*   Updated: 2021/09/15 00:04:45 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void sort_three(t_lists *lst)
{
	int max;
	int count;

	max = -2147483648;
	count = 0;
	while (count < lst->size_a)
	{
		if (lst->list_a[count] > max)
			max = lst->list_a[count];
		count++;
	}
	if (lst->list_a[lst->size_a - 1] == max)
		rotate_list(lst->list_a, lst->size_a);
	else if (lst->list_a[1] == max)
		reverse_rotate_list(lst->list_a, lst->size_a);
	if (lst->list_a[lst->size_a - 1] > lst->list_a[lst->size_a - 2])
		swap(lst->list_a, lst->size_a, 1);
}

static void sort_four_five(t_lists *lst, int signal)
{
	int min;
	int count;
	int pos;

	count = 0;
	min = 2147483647;
	while (count < lst->size_a)
	{
		if (lst->list_a[count] < min)
		{
			min = lst->list_a[count];
			pos = count;
		}
		count++;
	}
	verify_pos_to_push(lst->list_a, lst->size_a, pos);
	push_num_to_lst(lst, 0);
	if (signal == 5)
		sort_four_five(lst, 4);
	else
		sort_three(lst);
	push_num_to_lst(lst, 1);
}



void	sort_small_list(t_lists *lst)
{
	if (lst->size_a == 3)
		sort_three(lst);
	if (lst->size_a == 4)
		sort_four_five(lst, 4);
	if (lst->size_a == 5)
		sort_four_five(lst, 5);
	else
		if (lst->list_a[1] > lst->list_a[0])
			swap(lst->list_a, lst->size_a, 1);
}
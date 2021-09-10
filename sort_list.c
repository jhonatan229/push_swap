/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 15:44:08 by jestevam          #+#    #+#             */
/*   Updated: 2021/09/10 16:50:39 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void print_list(t_lists *list)
{
	int n = 0;
	while (n < list->size_a)
	{
		printf("list A %i: %i\n", n, list->list_a[n]);
		n++;
	}
	n = 0;
	printf("\n");
	while (n < list->size_b)
	{
		printf("list B %i: %i\n", n, list->list_b[n]);
		n++;
	}
}


static int	quantity_num(int num)
{
	int count;

	count = 0;
	if (num == -2147483648)
		return (10);
	if (num < 0)
		num = num * -1;
	while (num >= 10)
	{
		num /= 10;
		count++;
	}
	count++;
	return (count);
}

static int max_places(int *lst, int size, int max)
{
	int places;
	int aux;

	places = 0;
	while (--size > -1)
	{
		aux = quantity_num(lst[size]);
		if (aux > places && aux < max)
			places = aux;
	}
	return (places);
}

static int take_pos (int *lst, int size, int max)
{
	int num;
	int pos;

	num = 2147483647;
	while (--size > -1)
	{
		if (quantity_num(lst[size]) == max)
		{
			if (lst[size] < num)
			{
				num = lst[size];
				pos = size;
			}
		}
	}
	return (pos);
}

static void push_number(t_lists *lst, int pos)
{
	while (pos != lst->size_a - 1)
	{
		if (pos < lst->size_a / 2)
		{
			reverse_rotate_list(lst->list_a, lst->size_a);
			pos--;
		}
		else if (pos > lst->size_a / 2)
		{
			rotate_list(lst->list_a, lst->size_a);
			pos++;
		}
	}
	push_num_to_lst(lst, 0);
}

int	sort_list(t_lists *lst)
{
	int max_place;
	int pos;

	max_place = 11;
	while (verify_sort_list(lst->list_a, lst->size_a, 1) || lst->size_b)
	{
		max_place = max_places(lst->list_a, lst->size_a, max_place);
		pos = take_pos(lst->list_a, lst->size_a, max_place);
		push_number(lst, pos);
		printf("max %i, pos_min %i\n", max_place, pos);
		print_list(lst);
		exit(1);
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 15:44:08 by jestevam          #+#    #+#             */
/*   Updated: 2021/09/13 13:59:03 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void print_list(t_lists *list)
{
	int n = 0;
	printf("list A with %i itens\n", list->size_a);
	while (n < list->size_a)
	{
		printf("list A %i: %i\n", n, list->list_a[n]);
		n++;
	}
	n = 0;
	printf("list B with %i itens\n", list->size_b);
	while (n < list->size_b)
	{
		printf("list B %i: %i\n", n, list->list_b[n]);
		n++;
	}
	printf("\n");
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

static int max_places(int *lst, int size, int *max)
{
	int places;
	int aux;
	int	count;

	places = 0;
	count = 0;
	while (count < size)
	{
		aux = quantity_num(lst[count++]);
		if (aux > places && aux < *max)
			places = aux;
	}
	*max = places;
	places = 0;
	count = 0;
	while (count < size)
	{
		if (quantity_num(lst[count++]) == *max)
			places++;
	}
	return (places);
}

static int take_pos (int *lst, int size, int max)
{
	int num;
	int pos;

	num = 2147483647;
	pos = -1;
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
static void verify_pos_to_push(t_lists *lst, int pos)
{
	while (pos != lst->size_a - 1)
	{
		print_list(lst);
		if (pos <= lst->size_a / 2)
		{
			reverse_rotate_list(lst->list_a, lst->size_a);
			if (pos != 0)
				pos--;
			else
				pos = lst->size_a - 1;
		}
		else 
		{
			rotate_list(lst->list_a, lst->size_a);
			pos++;
		}
	}
}

static void push_number(t_lists *lst, int pos)
{
	verify_pos_to_push(lst, pos);
	push_num_to_lst(lst, 0);
	print_list(lst);
}

int	sort_list(t_lists *lst)
{
	int max_place;
	int pos;
	int quantity;

	max_place = 11;
	quantity = max_places(lst->list_a, lst->size_a, &max_place);
	while (verify_sort_list(lst->list_a, lst->size_a, 1) || lst->size_b)
	{
		while (quantity != 0)
		{
			pos = take_pos(lst->list_a, lst->size_a, max_place);
			printf("max %i, pos_min %i\n", max_place, pos);
			push_number(lst, pos);
			quantity--;
		}
		pos = take_pos(lst->list_a, lst->size_a, max_place + 1);
		if (pos > -1)
			verify_pos_to_push(lst, pos);
		while (lst->size_b)
			push_num_to_lst(lst, 1);
		print_list(lst);
		quantity = max_places(lst->list_a, lst->size_a, &max_place);
		//if (max_place == 0)
		//	exit(1);
	}
	return (0);
}
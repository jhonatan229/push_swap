/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 15:44:08 by jestevam          #+#    #+#             */
/*   Updated: 2021/09/13 23:36:27 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

//static void print_list(t_lists *list)
//{
//	int n = 0;
//	printf("list A with %i itens\n", list->size_a);
//	while (n < list->size_a)
//	{
//		printf("list A %i: %i\n", n, list->list_a[n]);
//		n++;
//	}
//	n = 0;
//	printf("list B with %i itens\n", list->size_b);
//	while (n < list->size_b)
//	{
//		printf("list B %i: %i\n", n, list->list_b[n]);
//		n++;
//	}
//	printf("\n");
//}


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

//max começa com 11
static int max_pos_places(int *lst, int size, int *max)
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
	count = -1;
	places = 0;
	while (++count < size)
		if (quantity_num(lst[count]) == *max && lst[count] >= 0)
			places++;
	return (places);
}

//max começa com 0
static int max_neg_places(int *lst, int size, int *max)
{
	int places;
	int aux;
	int	count;

	places = 10;
	count = 0;
	while (count < size)
	{
		aux = quantity_num(lst[count++]);
		if (aux < places && aux > *max)
			places = aux;
	}
	*max = places;
	count = -1;
	places = 0;
	while (++count < size)
		if (quantity_num(lst[count]) == *max && lst[count] < 0)
			places++;
	return (places);
}

static int take_positive_pos(int *lst, int size, int max)
{
	int num;
	int pos;
	int aux_size;

	num = 2147483647;
	pos = -1;
	aux_size = size;
	while (--size > -1)
	{
		if (quantity_num(lst[size]) == max && lst[size] >= 0)
		{
			if (lst[size] < num)
			{
				num = lst[size];
				pos = size;
			}
		}
	}
	if (pos == -1 && max <= 10)
		pos = take_positive_pos(lst, aux_size, max + 1);		
	return (pos);
}

static int link_signal_sorts(int *lst, int size, int max)
{
	int aux_size;
	int pos;
	int num;

	aux_size = size;
	pos = -1;
	num = 2147483647;
	while (--size > -1)
	{
		if (quantity_num(lst[size]) == max && lst[size] >= 0)
		{
			if (lst[size] < num)
			{
				num = lst[size];
				pos = size;
			}
		}
	}
	if (pos == -1 && max <= 10)
		pos = link_signal_sorts(lst, aux_size, max + 1);
	return (pos);
}

static int take_negative_pos(int *lst, int size, int max)
{
	int num;
	int pos;
	int aux_size;

	num = 0;
	pos = -1;
	aux_size = size;
	while (--size > -1)
	{
		if (quantity_num(lst[size]) == max && lst[size] < 0)
		{
			if (lst[size] < num)
			{
				num = lst[size];
				pos = size;
			}
		}
	}
	if (pos == -1 && max > 0)
		pos = take_negative_pos(lst, aux_size, max - 1);
	else if (pos == -1)
		pos = link_signal_sorts(lst, aux_size, 1);
	return (pos);
}

static void verify_pos_to_push(t_lists *lst, int pos)
{
	while (pos != lst->size_a - 1)
	{
		//print_list(lst);
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
	//print_list(lst);
}

static void sort_positive_numbers(t_lists *lst, int *max_place)
{
	int quantity;
	int pos;

	quantity = max_pos_places(lst->list_a, lst->size_a, max_place);
	while (quantity != 0)
	{
		pos = take_positive_pos(lst->list_a, lst->size_a, *max_place);
		//printf("max %i, pos_min %i, quanti: %i\n", *max_place, pos, quantity);
		//print_list(lst);
		push_number(lst, pos);
		quantity--;
	}
	pos = take_positive_pos(lst->list_a, lst->size_a, *max_place + 1);
	//printf("pos: %i\n", pos);
	if (pos > -1)
		verify_pos_to_push(lst, pos);
	while (lst->size_b)
		push_num_to_lst(lst, 1);
	//print_list(lst);
}

static void sort_negative_numbers(t_lists *lst, int *max_place)
{
	int quantity;
	int pos;

	quantity = max_neg_places(lst->list_a, lst->size_a, max_place);
	while (quantity != 0)
	{
		pos = take_negative_pos(lst->list_a, lst->size_a, *max_place);
		//printf("max %i, pos_min %i\n", *max_place, pos);
		//print_list(lst);
		push_number(lst, pos);
		quantity--;
	}
	pos = take_negative_pos(lst->list_a, lst->size_a, *max_place - 1);
	//printf("MY POS: %i\n", pos);
	if (pos > -1)
		verify_pos_to_push(lst, pos);
	while (lst->size_b)
		push_num_to_lst(lst, 1);
	//print_list(lst);
}

int	sort_list(t_lists *lst)
{
	int max_positive_place;
	int max_negative_place;

	max_positive_place = 11;
	max_negative_place = 0;
	while (verify_sort_list(lst->list_a, lst->size_a, 1) || lst->size_b)
	{
		if (max_positive_place != 0)
			sort_positive_numbers(lst, &max_positive_place);
		else if (max_negative_place != 10)
			sort_negative_numbers(lst, &max_negative_place);
		//if (max_place == 0)
		//	exit(1);
	}
	return (0);
}
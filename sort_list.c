/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 15:44:08 by jestevam          #+#    #+#             */
/*   Updated: 2021/09/15 00:37:55 by jestevam         ###   ########.fr       */
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

static void find_two_pos(t_lists *lst, int *f_pos, int *s_pos)
{
	int num;
	int count;

	count = 0;
	num = 2147483647;
	while (count < lst->size_a)
	{
		if (lst->list_a[count] < num)
		{
			*s_pos = *f_pos;
			*f_pos = count;
			num = lst->list_a[count];
		}
		count++;
	}
}

void verify_pos_to_push(int *lst, int size, int pos)
{
	while (pos != size - 1)
	{
		//print_list(lst);
		if (pos <= size / 2)
		{
			reverse_rotate_list(lst, size);
			if (pos != 0)
				pos--;
			else
				pos = size - 1;
		}
		else 
		{
			rotate_list(lst, size);
			pos++;
		}
	}
}

static int check_top_b(int *lst, int size, int num)
{
	int dif;
	int	pos;
	int count;

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

static void push_number(t_lists *lst, int pos)
{
	int	pos_b;
	
	verify_pos_to_push(lst->list_a, lst->size_a, pos);
	if (!lst->size_b)
		push_num_to_lst(lst, 0);
	else
	{
		pos_b = check_top_b(lst->list_b, lst->size_b, lst->list_a[lst->size_a - 1]);
		verify_pos_to_push(lst->list_b, lst->size_b, pos_b);
		push_num_to_lst(lst, 0);
	}
}

static void return_b_to_a(t_lists *lst)
{
	int count;
	int pos;
	int num;

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
	verify_pos_to_push(lst->list_b, lst->size_b, pos);
	while(lst->size_b)
		push_num_to_lst(lst, 1);
}

static void push_more_close(t_lists *lst, int f_pos, int s_pos)
{
	if (f_pos >= lst->size_a / 2 && s_pos >= lst->size_a / 2)
	{
		if (lst->size_a - f_pos < lst->size_a - s_pos)
			push_number(lst, f_pos);
		else
			push_number(lst, s_pos);
	}
	else if (f_pos < lst->size_a / 2 && s_pos < lst->size_a / 2)
	{
		printf("entrei poha\n");
		if (f_pos < s_pos)
			push_number(lst, f_pos);
		else
			push_number(lst, s_pos);
	}
	else if (f_pos < lst->size_a / 2 && s_pos > lst->size_a / 2)
	{
		if (f_pos < lst->size_a - s_pos)
			push_number(lst, f_pos);
		else
			push_number(lst, s_pos);
	}
	else if (f_pos >= lst->size_a / 2 && s_pos < lst->size_a / 2)
	{
		if (lst->size_a - f_pos < s_pos)
			push_number(lst, f_pos);
		else
			push_number(lst, s_pos);
	}
}

int	sort_list(t_lists *lst)
{
	int	first_pos;
	int	second_pos;

	first_pos = 0;
	second_pos = 0;
	if (lst->size_a <= 5)
		sort_small_list(lst);
	while (verify_sort_list(lst->list_a, lst->size_a, 1) || lst->size_b)
	{
		if (lst->size_a > 2)
		{
			find_two_pos(lst, &first_pos, &second_pos);
			push_more_close(lst, first_pos, second_pos);
		}
		else if (lst->size_a == 2)
			push_number(lst, 1);
		else
		{
			push_number(lst, 0);
			return_b_to_a(lst);
		}
		printf("number f: %i, number s: %i\n", first_pos, second_pos);
		print_list(lst);
		if (!lst->size_b)
			exit(1);
	}
	
	return (0);
}
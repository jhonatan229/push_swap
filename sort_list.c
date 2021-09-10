/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 15:44:08 by jestevam          #+#    #+#             */
/*   Updated: 2021/09/10 16:33:35 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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



int	sort_list(t_lists *lst)
{
	int max_place;
	int pos;

	max_place = 11;
	while (verify_sort_list(lst->list_a, lst->size_a, 1) || lst->size_b)
	{
		max_place = max_places(lst->list_a, lst->size_a, max_place);
		pos = take_pos(lst->list_a, lst->size_a, max_place);
		//push_number(lst, pos);
		printf("max %i, pos_min %i\n", max_place, pos);
		exit(1);
	}
	return (0);
}
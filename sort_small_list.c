/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 10:21:28 by jestevam          #+#    #+#             */
/*   Updated: 2021/09/14 11:30:47 by jestevam         ###   ########.fr       */
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
			max = lst->list_a[count++];
		count++;
	}
	if (lst->list_a[lst->size_a - 1] == max)
		rotate_list(lst->list_a, lst->size_a);
	else if (lst->list_a[1] == max)
		reverse_rotate_list(lst->list_a, lst->size_a);
	if (lst->list_a[lst->size_a - 1] > lst->list_a[lst->size_a - 2])
		swap(lst->list_a, lst->size_a, 1);
	count = 0;
}

void	sort_small_list(t_lists *lst)
{
	if (lst->size_a == 3)
		sort_three(lst);
}
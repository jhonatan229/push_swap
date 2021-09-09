/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:46:46 by jestevam          #+#    #+#             */
/*   Updated: 2021/09/09 17:21:19 by jestevam         ###   ########.fr       */
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

int main(int argc, char **argv)
{
	t_lists lst;
	int n;

	n = 0;
	lst.list_a = (int *)malloc(argc - 1);
	lst.list_b = (int *)malloc(argc - 1);
	while (n + 1< argc)
	{
		ft_isdigit(argv[n + 1], &lst);
		lst.list_a[n] = verify_number(ft_atoi(argv[n + 1], &lst), &lst);
		n++;
	}
	lst.size_a = n;
	lst.size_b = 0;
	print_list(&lst);
	swap(lst.list_a, argc - 1);
	put_lst_to_lst(&lst, 2);
	printf("\n\n");
	print_list(&lst);
	printf("\n\n");
	rotate_list(lst.list_b, lst.size_b);
	print_list(&lst);
	printf("\n\n");
	reverse_rotate_list(lst.list_b, lst.size_b);
	print_list(&lst);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:46:46 by jestevam          #+#    #+#             */
/*   Updated: 2021/09/10 16:01:52 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

//static void print_list(t_lists *list)
//{
//	int n = 0;
//	while (n < list->size_a)
//	{
//		printf("list A %i: %i\n", n, list->list_a[n]);
//		n++;
//	}
//	n = 0;
//	printf("\n");
//	while (n < list->size_b)
//	{
//		printf("list B %i: %i\n", n, list->list_b[n]);
//		n++;
//	}
//}

int main(int argc, char **argv)
{
	t_lists lst;
	int n;

	n = 0;
	lst.list_a = (int *)malloc(argc - 1);
	lst.list_b = (int *)malloc(argc - 1);
	argc--;
	while (argc != 0)
	{
		ft_isdigit(argv[argc], &lst);
		lst.list_a[n++] = verify_number(ft_atoi(argv[argc--], &lst), &lst);
	}
	lst.size_a = n;
	lst.size_b = 0;
	if (!verify_sort_list(lst.list_a, lst.size_a, 1))
		free_lst_exit(&lst, 0);
	sort_list(&lst);
	return (0);
}

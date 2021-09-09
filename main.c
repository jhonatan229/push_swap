/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:46:46 by jestevam          #+#    #+#             */
/*   Updated: 2021/09/09 13:18:09 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

//void put_lst_to_lst(int *lst_dst, int *lst_src, int size)
//{
//	if (lst_src)
//		return ;
//	
//}

void swap(int *lst, int size)
{
	int aux;
	
	if (size < 2)
		return ;
	aux = lst[size - 1];
	lst[size - 1] = lst[size - 2];
	lst[size - 2] = aux;
}

static void print_list(int *lst, int size)
{
	int n = 0;
	while (n < size)
	{
		printf("n %i: %i\n", n, lst[n]);
		n++;
	}
}

int main(int argc, char **argv)
{
	t_lists lst;
	int n;

	n = 0;
	lst.list_a = (int *)malloc(argc - 1);
	while (n + 1< argc)
	{
		ft_isdigit(argv[n + 1]);
		lst.list_a[n] = verify_number(ft_atoi(argv[n + 1]), lst.list_a);
		n++;
	}
	print_list(lst.list_a, argc - 1);
	swap(lst.list_a, argc - 1);
	printf("\n\n");
	print_list(lst.list_a, argc - 1);
	return (0);
}
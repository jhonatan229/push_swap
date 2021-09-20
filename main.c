/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:46:46 by jestevam          #+#    #+#             */
/*   Updated: 2021/09/20 13:33:21 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

//will take a scruct where is the two lists, and sort the numbers on list a
int	sort_list(t_lists *lst)
{
	int	max_chunk;
	int	last_in_chunk;

	max_chunk = 0;
	if (lst->size_a <= 5)
		sort_small_list(lst);
	while (verify_sort_list(lst->list_a, lst->size_a, 1) || lst->size_b)
	{
		if (max_chunk == 0)
		{
			last_in_chunk = -2147483648;
			max_chunk = find_max_chunk(lst, &last_in_chunk, max_chunk);
		}
		if (lst->size_a > 2)
			push_more_close(lst, last_in_chunk);
		else if (lst->size_a == 2)
			push_number(lst, 1);
		else
		{
			push_number(lst, 0);
			return_b_to_a(lst);
		}
		max_chunk--;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_lists	lst;
	int		n;

	n = 0;
	lst.list_a = (int *)calloc(argc - 1, sizeof(int));
	lst.list_b = (int *)calloc(argc - 1, sizeof(int));
	argc--;
	while (argc != 0)
	{
		ft_isdigit(argv[argc], &lst);
		lst.list_a[n] = verify_number(ft_atoi(argv[argc--], &lst), &lst, n);
		n++;
	}
	lst.size_a = n;
	lst.size_b = 0;
	if (!verify_sort_list(lst.list_a, lst.size_a, 1))
		free_lst_exit(&lst, 0);
	sort_list(&lst);
	free_lst_exit(&lst, 0);
	return (0);
}

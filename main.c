/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:46:46 by jestevam          #+#    #+#             */
/*   Updated: 2021/09/16 16:07:09 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	sort_list(t_lists *lst)
{
	int	max_chunck;
	int	last_in_chunck;

	max_chunck = 0;
	if (lst->size_a <= 5)
		sort_small_list(lst);
	while (verify_sort_list(lst->list_a, lst->size_a, 1) || lst->size_b)
	{
		if (max_chunck == 0)
		{
			last_in_chunck = -2147483648;
			max_chunck = find_max_chunck(lst, &last_in_chunck, max_chunck);
		}
		if (lst->size_a > 2)
			push_more_close(lst, last_in_chunck);
		else if (lst->size_a == 2)
			push_number(lst, 1);
		else
		{
			push_number(lst, 0);
			return_b_to_a(lst);
		}
		max_chunck--;
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
	return (0);
}

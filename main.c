/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:46:46 by jestevam          #+#    #+#             */
/*   Updated: 2021/09/15 14:45:33 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int main(int argc, char **argv)
{
	t_lists lst;
	int n;

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

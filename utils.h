/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 23:21:36 by jestevam          #+#    #+#             */
/*   Updated: 2021/09/15 14:58:53 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(UTILS_H)
#define UTILS_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_lists{
	int *list_a;
	int *list_b;
	int size_a;
	int size_b;
}			t_lists;

int 	ft_isdigit(char *str, t_lists *list);
int		ft_atoi(const char *nptr, t_lists *list);
int		verify_number(int add, t_lists *list, int limit);
void	swap(int *lst, int size, int signal);
void	push_num_to_lst(t_lists *list, int signal);
void	reverse_rotate_list(int *lst, int size, int signal);
void	rotate_list(int *lst, int size, int signal);
int		verify_sort_list(int *lst, int size, int signal);
void	free_lst_exit(t_lists *list, int signal);
int		sort_list(t_lists *lst);
void	sort_small_list(t_lists *lst);
void 	verify_pos_to_push(int *lst, int size, int pos, int signal);

#endif // UTILS_H

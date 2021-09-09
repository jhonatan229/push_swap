/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 23:21:36 by jestevam          #+#    #+#             */
/*   Updated: 2021/09/09 13:14:24 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(UTILS_H)
#define UTILS_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_lists{
	int *list_a;
	int *list_b;
	int size_a;
	int size_b;
}			t_lists;

int	ft_isdigit(char *str);
int	ft_atoi(const char *nptr);
int	verify_number(int add, int *list);

#endif // UTILS_H

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:48:30 by ahaarij           #+#    #+#             */
/*   Updated: 2024/03/17 16:19:06 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/includes/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_stacks
{
    int     *a;
    int     *b;
    int     a_size;
    int     b_size;
    char    *join_args;
}           t_stacks;

void    free_and_exit_msg(t_stacks *s, char *msg);
void    initialize_stacks(int argc, char **argv, t_stacks *s);
void    exit_if_dupes_or_sorted(t_stacks *s, int i);
void    parse_numbers(t_stacks *s);
int	    ft_atol(const char *n, t_stacks *s);
int	    is_array_sorted(t_stacks *s);
void	swap(char *str, int *arr, int size);
void	sort_three_elements(t_stacks *s);
void	rotate(int *array, int size, char *dir, char *list);
void	radix_sort(t_stacks *s);
void	push(char *str, t_stacks *s);
void	sort_four_to_five_elements(t_stacks *s);

#endif
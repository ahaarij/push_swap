/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:48:30 by ahaarij           #+#    #+#             */
/*   Updated: 2024/03/06 16:55:14 by ahaarij          ###   ########.fr       */
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

#endif
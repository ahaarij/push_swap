/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:01:04 by ahaarij           #+#    #+#             */
/*   Updated: 2024/03/06 16:54:48 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    initialize_stacks(int argc, char **argv, t_stacks *s)
{
    int i;
    
    i = 0;
    s->a_size = 0;
    s->b_size = 0;
    while(--argc)
    {
        if (wordcount(argv[i + 1], ' '))
            s->a_size += wordcount(argv[i + 1], ' ');
        else
            s->a_size++;
        i++;
    }
    s->a = malloc(s->a_size * sizeof s->a);
    if (s->a == NULL)
        free_and_exit_msg(s, "Error\n");
    s->b = malloc(s->a_size * sizeof s->b);
    if (s->b == NULL)
        free_and_exit_msg(s, "Error\n");
}

void    parse_numbers(t_stacks *s)
{
    char    **temp;
    int     i;
    int     j;
    
    j = 0;
    temp = ft_split(s->join_args, ' ');
    i = 0;
    while(temp[i] != NULL && temp[i][0] != NULL)
    {
        s->a[j++] = ft_atol(temp[i++], s);
        free(temp[i - 1]);
    }
    free(temp);
}

int	ft_atol(const char *n, t_stacks *s)
{
	int			i;
	long		sign;
	long long	res;

	res = 0;
	sign = 1;
	i = 0;
	while (n[i] == ' ' || (n[i] >= '\t' && n[i] <= '\r'))
		i++;
	if ((n[i] == '+' || n[i] == '-'))
	{
		if (n[i] == '-')
			sign = -1;
		i++;
	}
	while (n[i])
	{
		if (res > 2147483647 || (res * sign) < -2147483648 || ft_strlen(n) > 11)
			free_and_exit_with_message(s, "Error\n");
		if (!(n[i] >= '0' && n[i] <= '9'))
			free_and_exit_with_message(s, "Error\n");
		res = res * 10 + (n[i++] - '0');
	}
	return ((int)(res * sign));
}
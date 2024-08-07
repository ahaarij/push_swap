/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:01:04 by ahaarij           #+#    #+#             */
/*   Updated: 2024/04/15 11:44:10 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	create_index(t_stacks *s)
{
	int	i;
	int	j;
	int	k;
	int	*new_a;

	new_a = malloc(s->a_size * sizeof * new_a);
	if (new_a == NULL)
		free_and_exit_msg(s, "Error\n");
	i = -1;
	while (++i < s->a_size)
	{
		k = 0;
		j = -1;
		while (++j < s->a_size)
			if (s->a[i] > s->a[j])
				k++;
		new_a[i] = k;
	}
	i = s->a_size;
	while (i--)
		s->a[i] = new_a[i];
	free(new_a);
}

void	initialize_stacks(int argc, char **argv, t_stacks *s)
{
	int	i;

	i = 0;
	s->a_size = 0;
	s->b_size = 0;
	while (--argc)
	{
		if (ft_count_words(argv[i + 1], ' '))
			s->a_size += ft_count_words(argv[i + 1], ' ');
		else
			s->a_size++;
		i++;
	}
	s->a = malloc (s->a_size * sizeof * s->a);
	if (s->a == NULL)
		free_and_exit_msg(s, "Error\n");
	s->b = malloc (s->a_size * sizeof * s->b);
	if (s->b == NULL)
		free_and_exit_msg(s, "Error\n");
}

void	exit_if_dupes_or_sorted(t_stacks *s, int i)
{
	int	j;

	j = 0;
	if (i == 0)
	{
		while (i < s->a_size)
		{
			j = i + 1;
			while (j < s->a_size)
			{
				if (s->a[i] == s->a[j])
					free_and_exit_msg(s, "Error\n");
				j++;
			}
			i++;
		}
	}
	if (is_array_sorted(s))
		free_and_exit_msg(s, NULL);
}

void	parse_numbers(t_stacks *s)
{
	char	**temp;
	int		i;
	int		j;

	j = 0;
	temp = ft_split(s->join_args, ' ');
	i = 0;
	while (temp[i] != NULL && temp[i][0] != '\0')
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
		if (!(n[i] >= '0' && n[i] <= '9'))
			free_and_exit_msg(s, "Error\n");
		res = res * 10 + (n[i++] - '0');
		if ((res * sign) < INT_MIN || (res * sign) > INT_MAX
			|| ft_strlen(n) > 11)
			free_and_exit_msg(s, "Error\n");
	}
	return ((int)(res * sign));
}

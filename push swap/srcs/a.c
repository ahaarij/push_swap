/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:48:00 by ahaarij           #+#    #+#             */
/*   Updated: 2024/03/17 16:18:25 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    free_and_exit_msg(t_stacks *s, char *msg)
{
    if (msg)
        write(2, msg, ft_strlen(msg));
    if (s != NULL)
    {
        if (s->a != NULL)
			free(s->a);
		if (s->b != NULL)
			free(s->b);
		if (s->join_args != NULL)
			free(s->join_args);
		if (s != NULL)
			free(s);
    }
    exit (1);
}


static void validate_args(int argc, char **argv)
{
    int i;
    int j;

    i = 0;
    if (argc > 2)
        free_and_exit_msg(NULL, "");
    while (++i < argc)
    {
        j = 0;
        if(!argv[1][0] || (argv[i][0] && argv[i][0] == ' '))
            free_and_exit_msg(NULL, "Error\n");
        while(argv[i][j] != '\0')
        {
            if ((!(ft_isdigit(argv[i][j])) && (argv[i][j] != ' ')
			&& (argv[i][j] != '-' && argv[i][j] != '+' && argv[i][j] != ' '))
			|| (argv[i][j] == '-' && argv[i][j + 1] == '\0')
			|| (argv[i][j] == '+' && argv[i][j + 1] == '\0')
			|| (argv[i][j] == '-' && argv[i][j + 1] == ' ')
			|| (argv[i][j] == '+' && argv[i][j + 1] == ' '))
				free_and_exit_msg(NULL, "Error\n");
            j++;
        }
    }
}

static void join_args(int argc, char **argv, t_stacks *s)
{
    char	*temp;
	char	*temp2;
	int		i;

	i = 0;
	temp2 = ft_strdup("");
	while(++i < argc && argv[i] != NULL)
	{
		temp = ft_strjoin(temp2, argv[i]);
		if (temp2)
			free(temp2);
		if (i != argc - 1)
		{
			temp2 = ft_strjoin(temp, " ");
			if (temp)
				free(temp);
			temp = temp2;
		}
	}
	s->join_args = ft_strdup(NULL);
	if (s->join_args == NULL)
		free_and_exit_msg(s, "Error\n");
	if (temp)
		free(temp);
}


int main(int argc, char **argv)
{
    t_stacks *s;
    
    validate_args(argc, argv);
    s = malloc(sizeof * s);
    if (s == NULL)
        exit (1);
    initialize_stacks(argc, argv, s);
    join_args(argc, argv, s);
	parse_numbers(s);
	exit_if_dupes_or_sorted(s, 0);
	if (s->a_size == 2 && s->a[0] > s->a[1])
		swap("sa", s->a, s->a_size);
	else if (s->a_size == 3)
		sort_three_elements(s);
	else if (s->a_size == 5)
		sort_four_to_five_elements(s);
	else
		radix_sort(s);
	exit_if_dupes_or_sorted(s, 1);
	free_and_exit_msg(s, "Error\n");
	return (0);
}
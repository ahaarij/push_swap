/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:32:29 by ahaarij           #+#    #+#             */
/*   Updated: 2024/01/23 12:32:17 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// int	ft_printstr(char *str)
// {
// 	unsigned int	len;

// 	if (!str)
// 	{
// 		ft_putstr_fd("(null)", 1);
// 		return (6);
// 	}
// 	ft_putstr_fd(str, 1);
// 	len = ft_strlen(str);
// 	return (len);
// }

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
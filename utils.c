/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:05:31 by arashido          #+#    #+#             */
/*   Updated: 2023/08/15 13:09:24 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_empty_quote(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (((unsigned char)str[i]) != ' ')
			return (false);
		i++;
	}
	return (true);
}

bool	has_empty_quotes(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_empty_quote(argv[i]))
			return (true);
		i++;
	}
	return (false);
}

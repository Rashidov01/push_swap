/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:05:31 by arashido          #+#    #+#             */
/*   Updated: 2023/08/07 21:34:52 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_arr(char **p)
{
	int	i;

	i = 0;
	while (p != NULL && p[i])
	{
		free(p[i]);
		i++;
	}
	if (p)
	{
		free(p);
		p = NULL;
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t	ft_strspn(const char *str, const char *charset)
{
	size_t	count;

	count = 0;
	while (*str && ft_strchr(charset, *str))
	{
		count++;
		str++;
	}
	return (count);
}

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:58:15 by arashido          #+#    #+#             */
/*   Updated: 2023/08/04 21:58:31 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_2(const char *str)
{
	int	index;
	int	result;
	int	sign;

	index = 0;
	result = 0;
	sign = 1;
	while (str[index] == 32 || (str[index] >= 9 && str[index] <= 13))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while (str[index] && ft_isdigit(str[index]))
	{
		result = (result * 10) + str[index] - 48;
		if (result > INT_MAX || result < INT_MIN)
			return (0);
		index++;
	}
	if (str[index] && !ft_isdigit(str[index]))
		return (0);
	return (result * sign);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

bool	check_duplicate(char **argv)
{
	int	i;
	int	j;

	i = -1;
	while (argv[++i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (0);
			j++;
		}
	}
	return (1);
}

char	*join_argv(char **argv)
{
	char	*str;

	int i, j, k;
	i = -1;
	k = 0;
	while (argv[++i])
		k += ft_strlen(argv[i]);
	str = (char *)malloc(k + i);
	if (!str)
		return (NULL);
	i = -1;
	k = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
			str[k++] = argv[i][j];
		if (argv[i + 1])
			str[k++] = ' ';
	}
	str[k] = '\0';
	return (str);
}

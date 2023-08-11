/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <avazbekrashidov6@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:58:15 by arashido          #+#    #+#             */
/*   Updated: 2023/08/12 01:17:56 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int		i;
	int		j;
	int		k;

	i = -1;
	k = 0;
	while (argv[++i])
		k += ft_strlen(argv[i]);
	str = (char *)malloc(k + i + 1);
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

char	**split_argv(char **argv)
{
	char	*str;
	char	**arr;
	size_t	i;
	size_t	whitespace_count;

	str = join_argv(argv);
	arr = ft_split(str, ' ');
	i = 0;
	while (arr[i] != NULL)
	{
		whitespace_count = ft_strspn(arr[i], " \t\n\v\f\r");
		arr[i] += whitespace_count;
		i++;
	}
	free(str);
	return (arr);
}

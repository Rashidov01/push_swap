/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:58:15 by arashido          #+#    #+#             */
/*   Updated: 2023/08/17 14:32:15 by arashido         ###   ########.fr       */
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
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (false);
			j++;
		}
	}
	return (true);
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
	free(str);
	while (arr[i] != NULL)
	{
		whitespace_count = ft_strspn(arr[i], " \t\n\v\f\r");
		arr[i] += whitespace_count;
		i++;
	}
	return (arr);
}

int	is_sorted(t_list *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

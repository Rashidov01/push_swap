/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:06:13 by arashido          #+#    #+#             */
/*   Updated: 2023/08/04 21:58:39 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	*concatenated;
	char	**split_argv;
	int		i;

	i = 0;
	if (argc < 2)
		return (1);
	++argv;
	while (argv[++i])
	{
		if (ft_atoi_2(argv[i]) == 0)
		{
			printf("Error: Invalid argument\n");
			return (1);
		}
	}
	if (!check_duplicate(argv + 1))
	{
		printf("Duplicate found in command-line arguments.\n");
		return (1);
	}
	concatenated = join_argv(argv);
	if (concatenated)
	{
		split_argv = ft_split(concatenated, ' ');
		i = 0;
		while (split_argv[i])
		{
			printf("Element %d: %s\n", i, split_argv[i]);
			i++;
		}
		free(concatenated);
		ft_free_arr(split_argv);
	}
	else
	{
		printf("Error: Memory allocation failed\n");
		return (1);
	}
	// check for int; int max; duplicates; if okay use atoi
	// ft_strjoin and then split -- to take care of quotes;
	// create stack use lstaddtoback;
	// sort
}

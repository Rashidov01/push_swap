/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 08:54:43 by arashido          #+#    #+#             */
/*   Updated: 2023/08/12 13:46:10 by arashido         ###   ########.fr       */
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

int	error(int argc, char **argv, t_list **stack_a)
{
	char		**split;
	int			i;
	int			arg_index;
	t_list		*tmp;
	long int	num;

	arg_index = 1;
	if (has_empty_quotes(argc, argv))
	{
		write(2, "Error: Empty quotes detected.\n", 30);
		exit(1);
	}
	while (arg_index < argc && ft_strspn(argv[arg_index],
			" ") == ft_strlen(argv[arg_index]))
		arg_index++;
	if (arg_index == argc)
	{
		write(2, "Error: No valid input provided.\n", 33);
		return (1);
	}
	i = arg_index;
	split = split_argv(argv + arg_index);
	i = 0;
	if (split == NULL)
	{
		write(2, "Error: No valid input provided.\n", 33);
		return (1);
	}
	while (split[i])
	{
		if (check_digit_str(split[i]) == 0)
		{
			printf("Invalid argument found\n");
			exit(1);
		}
		num = ft_atoi(split[i]);
		if (num >= INT_MIN && num <= INT_MAX)
			tmp = ft_lstnew(num);
		else
		{
			printf("Found invalid number\n");
			exit(1);
		}
		ft_lstadd_back(stack_a, tmp);
		i++;
	}
	if (!check_duplicate(split))
	{
		write(2, "Duplicate found\n", 16);
		exit(1);
	}
	return (0);
}

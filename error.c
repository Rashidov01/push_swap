/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 08:54:43 by arashido          #+#    #+#             */
/*   Updated: 2023/08/12 22:59:45 by arashido         ###   ########.fr       */
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

static int	ft_norm(int arg_index, int ind)
{
	if (arg_index == ind)
	{
		write(2, "Error: No valid input provided.\n", 33);
		return (1);
	}
	return (0);
}

static void	ft_norm2(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

static void	ft_norm3(char **split, long int num, t_list *tmp, t_list **stack_a)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (check_digit_str(split[i]) == 0)
			ft_norm2("Invalid argument found");
		num = ft_atoi(split[i]);
		if (num >= INT_MIN && num <= INT_MAX)
			tmp = ft_lstnew(num);
		else
			ft_norm2("Found invalid argv");
		ft_lstadd_back(stack_a, tmp);
		// if(if_sorted(*stack_a) == 1)
		// 	printf("stack is sorted");
		i++;
	}
}

int	error(int argc, char **argv, t_list **stack_a)
{
	char		**split;
	int			arg_index;
	t_list		*tmp;
	long int	num;

	tmp = NULL;
	num = 0;
	arg_index = 1;
	if (has_empty_quotes(argc, argv))
		ft_norm2("Error: Empty quotes detected");
	while (arg_index < argc && ft_strspn(argv[arg_index],
			" ") == ft_strlen(argv[arg_index]))
		arg_index++;
	ft_norm(arg_index, argc);
	split = split_argv(argv + arg_index);
	if (split == NULL)
		return (write(2, "Error: No valid input provided.\n", 33), 1);
	ft_norm3(split, num, tmp, stack_a);
	if (!check_duplicate(split))
		ft_norm2("Duplicate found");
	return (0);
}

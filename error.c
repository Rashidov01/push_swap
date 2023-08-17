/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 08:54:43 by arashido          #+#    #+#             */
/*   Updated: 2023/08/17 18:36:56 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_argv(int arg_index, int ind)
{
	if (arg_index == ind)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

static void	str_split(char **split, long long num, t_list *tmp, t_stacks *stack)
{
	int	i;

	i = 0;
	split = replace_with_index(split);
	while (split[i])
	{
		if (check_digit_str(split[i]) == 0)
		{
			write(2, "Error\n", 6);
			free_split(split);
			free_stack(stack);
			exit(1);
		}
		num = ft_atoi2(split[i], stack, split);
		if (num >= INT_MIN && num <= INT_MAX)
			tmp = ft_lstnew(num);
		else
		{
			write(2, "Error\n", 6);
			free_split(split);
			free_stack(stack);
			exit(1);
		}
		ft_lstadd_back(&stack->stack_a, tmp);
		i++;
	}
}

static void	check_empty_argv(int arg_index, int argc, char **argv)
{
	while (arg_index < argc && ft_strspn(argv[arg_index],
			" ") == ft_strlen(argv[arg_index]))
		arg_index++;
}

static void	check_duplicate_fn(char **split, t_stacks *stack)
{
	if (!check_duplicate(split))
	{
		free_split(split);
		free_all(stack);
	}
}

int	error(int argc, char **argv, t_stacks *stack)
{
	long long int	num;
	t_list			*tmp;
	char			**split;
	int				arg_index;

	tmp = NULL;
	num = 0;
	arg_index = 1;
	if (has_empty_quotes(argc, argv))
		free_all(stack);
	check_empty_argv(arg_index, argc, argv);
	check_argv(arg_index, argc);
	split = split_argv(argv + arg_index);
	if (split == NULL)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	str_split(split, num, tmp, stack);
	check_duplicate_fn(split, stack);
	free_split(split);
	return (0);
}

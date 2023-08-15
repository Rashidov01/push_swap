/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 08:54:43 by arashido          #+#    #+#             */
/*   Updated: 2023/08/15 13:07:11 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	err_message(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static int	check_argv(int arg_index, int ind)
{
	if (arg_index == ind)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

static void	ft_norm(char **split, long long num, t_list *tmp, t_list **stack_a)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (check_digit_str(split[i]) == 0)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		num = ft_atoi(split[i]);
		if (num >= INT_MIN && num <= INT_MAX)
			tmp = ft_lstnew(num);
		else
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		ft_lstadd_back(stack_a, tmp);
		i++;
	}
}

static void	check_empty_argv(int arg_index, int argc, char **argv)
{
	while (arg_index < argc && ft_strspn(argv[arg_index],
			" ") == ft_strlen(argv[arg_index]))
		arg_index++;
}

int	error(int argc, char **argv, t_list **stack_a)
{
	long long int	num;
	t_list			*tmp;
	char			**split;
	int				i;
	int				arg_index;

	tmp = NULL;
	num = 0;
	arg_index = 1;
	if (has_empty_quotes(argc, argv))
		err_message();
	check_empty_argv(arg_index, argc, argv);
	check_argv(arg_index, argc);
	i = arg_index;
	split = split_argv(argv + arg_index);
	i = 0;
	if (split == NULL)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	ft_norm(split, num, tmp, stack_a);
	if (!check_duplicate(split))
		err_message();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_atoi2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:30:32 by arashido          #+#    #+#             */
/*   Updated: 2023/08/26 17:59:29 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_whitespace(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

static int	get_sign(const char *str, int *index)
{
	int	sign;

	sign = 1;
	if (str[*index] == '-' || str[*index] == '+')
	{
		if (str[*index] == '-')
			sign = -1;
		(*index)++;
	}
	return (sign);
}

static void	handle_overfloww(long long int *tmp, t_stacks *stack, char **split,
		char **og_split)
{
	if (tmp[1] > tmp[0])
	{
		write(2, "Error\n", 6);
		free_split(split);
		free_split(og_split);
		ft_free_list(stack->stack_a);
		ft_free_list(stack->stack_b);
		free(stack);
		exit(1);
	}
}

long long int	ft_atoi3(const char *str, t_stacks *stack, char **split,
		char **og_split)
{
	long long int	tmp[2];
	int				index;
	int				sign;

	index = 0;
	tmp[0] = 0;
	while (is_whitespace(str[index]))
		index++;
	sign = get_sign(str, &index);
	while (str[index] >= '0' && str[index] <= '9')
	{
		tmp[1] = tmp[0];
		tmp[0] = (tmp[0] * 10) + str[index] - '0';
		handle_overfloww(tmp, stack, split, og_split);
		index++;
	}
	return (tmp[0] * sign);
}

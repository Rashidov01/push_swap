/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:08:29 by arashido          #+#    #+#             */
/*   Updated: 2023/08/15 13:09:10 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_overflow(long long int tmp, long long int result)
{
	if (tmp > result)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

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

long long int	ft_atoi(const char *str)
{
	long long int	tmp;
	long long int	result;
	int				index;
	int				sign;

	index = 0;
	result = 0;
	while (is_whitespace(str[index]))
		index++;
	sign = get_sign(str, &index);
	while (str[index] >= '0' && str[index] <= '9')
	{
		tmp = result;
		result = (result * 10) + str[index] - '0';
		handle_overflow(tmp, result);
		index++;
	}
	return (result * sign);
}

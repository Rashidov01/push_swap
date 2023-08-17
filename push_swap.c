/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:06:13 by arashido          #+#    #+#             */
/*   Updated: 2023/08/17 17:33:53 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	full_sort(t_stacks *stacks)
{
	int	stack_size;

	stack_size = ft_lstsize(stacks->stack_a);
	if (is_sorted(stacks->stack_a))
		return ;
	else if (stack_size == 2)
		sort_2(&stacks->stack_a);
	else if (stack_size == 3)
		sort_3(&stacks->stack_a);
	else if (stack_size == 4)
		sort_4(stacks);
	else if (stack_size == 5)
		sort_5(stacks);
	else
		big_sort(stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc < 2)
	{
		return (0);
		exit(0);
	}
	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (0);
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	error(argc, argv, stacks);
	full_sort(stacks);
	ft_free_list(stacks->stack_a);
	free(stacks);
	return (0);
}

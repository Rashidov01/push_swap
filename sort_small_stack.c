/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 20:36:23 by arashido          #+#    #+#             */
/*   Updated: 2023/08/15 13:35:17 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_the_smallest(t_list *stack_a)
{
	int	smallest;
	int	current;

	smallest = INT_MAX;
	while (stack_a)
	{
		current = stack_a->content;
		if (current < smallest)
			smallest = current;
		stack_a = stack_a->next;
	}
	return (smallest);
}

static void	sort_helper(t_stacks *stacks)
{
	ft_pb(stacks);
	sort_3(&stacks->stack_a);
	ft_pa(stacks);
}

void	sort_4(t_stacks *stacks)
{
	long long	small;

	small = find_the_smallest(stacks->stack_a);
	if (stacks->stack_a->content == small)
		sort_helper(stacks);
	else if (stacks->stack_a->next->content == small)
	{
		ft_sa(&stacks->stack_a);
		sort_helper(stacks);
	}
	else if (stacks->stack_a->next->next->content == small)
	{
		ft_rra(&stacks->stack_a);
		ft_rra(&stacks->stack_a);
		sort_helper(stacks);
	}
	else if (stacks->stack_a->next->next->next->content == small)
	{
		ft_rra(&stacks->stack_a);
		sort_helper(stacks);
	}
}

void	sort_5(t_stacks *stacks)
{
	int	smallest;

	if (is_sorted(stacks->stack_a))
		return ;
	smallest = find_the_smallest(stacks->stack_a);
	while (stacks->stack_a->content != smallest)
	{
		if (get_min_pos(stacks->stack_a, smallest) <= 2)
			ft_ra(&stacks->stack_a);
		else
			ft_rra(&stacks->stack_a);
	}
	ft_pb(stacks);
	smallest = find_the_smallest(stacks->stack_a);
	while (stacks->stack_a->content != smallest)
	{
		if (get_min_pos(stacks->stack_a, smallest) <= 2)
			ft_ra(&stacks->stack_a);
		else
			ft_rra(&stacks->stack_a);
	}
	ft_pb(stacks);
	sort_3(&stacks->stack_a);
	ft_pa(stacks);
	ft_pa(stacks);
}

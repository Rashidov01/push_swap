/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 20:36:23 by arashido          #+#    #+#             */
/*   Updated: 2023/08/13 18:25:41 by arashido         ###   ########.fr       */
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

void	sort_small_stack(t_stacks *stacks)
{
	t_list	**stack_a;
	t_list	**stack_b;

	stack_a = &(stacks->stack_a);
	stack_b = &(stacks->stack_b);
	while (ft_lstsize(*stack_a) > 0)
	{
		if ((*stack_a)->content == find_the_smallest(*stack_a))
			ft_pb(stacks);
		else
			ft_ra(stack_a);
	}
	while (*stack_b)
		ft_pa(stacks);
}

// void	sort_small_stack(t_stacks *stacks)
// {
// 	t_list	**stack_a;
// 	t_list	**stack_b;
// 	int		smallest;
// 	int		size;

// 	stack_a = &(stacks->stack_a);
// 	stack_b = &(stacks->stack_b);
// 	while (*stack_a)
// 	{
// 		smallest = find_the_smallest(*stack_a);
// 		size = ft_lstsize(*stack_a);
// 		if ((*stack_a)->content == smallest)
// 		{
// 			ft_pb(stacks);
// 		}
// 		else if ((*stack_a)->next->content == smallest)
// 		{
// 			ft_sa(&stacks->stack_a);
// 		}
// 		else if ((*stack_a)->next->next->content == smallest)
// 		{
// 			ft_rra(stack_a);
// 		}
// 		else
// 		{
// 			ft_ra(stack_a);
// 		}
// 	}
// 	while (*stack_b)
// 		ft_pa(stacks);
// }

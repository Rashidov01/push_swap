/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:57:04 by arashido          #+#    #+#             */
/*   Updated: 2023/08/13 12:57:54 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push a and b
void	ft_pb(t_stacks *stacks)
{
	t_list	*first;

	if (stacks->stack_a == NULL)
		return ;
	first = stacks->stack_a;
	stacks->stack_a = stacks->stack_a->next;
	first->next = stacks->stack_b;
	stacks->stack_b = first;
}

void	ft_pa(t_stacks *stacks)
{
	t_list	*first;

	if (stacks->stack_b == NULL)
		return ;
	first = stacks->stack_b;
	stacks->stack_b = stacks->stack_b->next;
	first->next = stacks->stack_a;
	stacks->stack_a = first;
}

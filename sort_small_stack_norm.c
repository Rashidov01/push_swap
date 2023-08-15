/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack_norm.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:30:05 by arashido          #+#    #+#             */
/*   Updated: 2023/08/14 23:39:34 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_pos(t_list *stack_a, int min)
{
	int		pos;
	t_list	*tmp;

	pos = 1;
	tmp = stack_a;
	while (tmp)
	{
		if (tmp->content == min)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

void	sort_2(t_list **stack_a)
{
	int	a;
	int	b;

	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	if (a > b)
		ft_sa(stack_a);
}

void	sort_3(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;
	if (a > b && b > c)
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if (a > b && a > c && c > b)
		ft_ra(stack_a);
	else if (a > b && a < c && c > b)
		ft_sa(stack_a);
	else if (a < b && b > c && a > c)
		ft_rra(stack_a);
	else if (a < b && b > c && a < c)
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
}

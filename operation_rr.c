/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:55:46 by arashido          #+#    #+#             */
/*   Updated: 2023/08/13 18:24:47 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// reverse rotate a, b and both rrr
void	ft_rra(t_list **a)
{
	int		len;
	t_list	*first;
	t_list	*last;

	len = ft_lstsize(*a);
	if (len <= 1)
		return ;
	last = *a;
	while (last && last->next && last->next->next)
		last = last->next;
	first = last->next;
	first->next = *a;
	*a = first;
	last->next = NULL;
	ft_printf("rra\n");
}

void	ft_rrb(t_list **b)
{
	int		len;
	t_list	*first;
	t_list	*last;

	len = ft_lstsize(*b);
	if (len <= 1)
		return ;
	last = *b;
	while (last && last->next && last->next->next)
		last = last->next;
	first = last->next;
	first->next = *b;
	*b = first;
	last->next = NULL;
	ft_printf("rrb\n");
}

void	ft_rrr(t_list **a, t_list **b)
{
	ft_rra(a);
	ft_rrb(b);
	ft_printf("rrr\n");
}

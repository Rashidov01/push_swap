/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:28:28 by arashido          #+#    #+#             */
/*   Updated: 2023/08/28 12:32:14 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rotate a, b and rr rotate both
void	ft_ra(t_list **a)
{
	int		len;
	t_list	*first;
	t_list	*last;

	len = ft_lstsize(*a);
	if (len <= 1)
		return ;
	last = *a;
	first = *a;
	while (last->next)
		last = last->next;
	last->next = first;
	*a = (*a)->next;
	first->next = NULL;
	ft_printf("ra\n");
}

void	ft_rb(t_list **b)
{
	int		len;
	t_list	*first;
	t_list	*last;

	len = ft_lstsize(*b);
	if (len <= 1)
		return ;
	first = *b;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = first;
	*b = (*b)->next;
	first->next = NULL;
	ft_printf("rb\n");
}

void	ft_rr(t_list **a, t_list **b)
{
	ft_ra(a);
	ft_rb(b);
	ft_printf("rr\n");
}

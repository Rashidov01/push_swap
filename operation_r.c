/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <avazbekrashidov6@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:28:28 by arashido          #+#    #+#             */
/*   Updated: 2023/08/12 01:16:04 by arashido         ###   ########.fr       */
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
}

void	ft_rr(t_list **a, t_list **b)
{
	ft_ra(a);
	ft_rb(b);
}

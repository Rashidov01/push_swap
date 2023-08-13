/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:56:33 by arashido          #+#    #+#             */
/*   Updated: 2023/08/13 12:58:03 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list **a)
{
	int	tmp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	tmp = (*a)->content;
	(*a)->content = (*a)->next->content;
	(*a)->next->content = tmp;
}

void	ft_sb(t_list **b)
{
	int	tmp;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	tmp = (*b)->content;
	(*b)->content = (*b)->next->content;
	(*b)->next->content = tmp;
}

void	ft_ss(t_list **a, t_list **b)
{
	ft_sa(a);
	ft_sb(b);
}

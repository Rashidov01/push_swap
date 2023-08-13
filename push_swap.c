/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:06:13 by arashido          #+#    #+#             */
/*   Updated: 2023/08/13 18:16:30 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_stack(t_list *a)
{
	t_list	*tmp;

	tmp = a;
	ft_printf("=======Stack======\n");
	while (tmp)
	{
		ft_printf("num: %d\n", tmp->content);
		tmp = tmp->next;
	}
	ft_printf("=======END=======\n\n");
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	stacks->stack_a = NULL;
	if (argc < 2)
	{
		write(2, "less parameter\n", 16);
		exit(1);
	}
	error(argc, argv, &(stacks->stack_a));
	// display_stack(stacks->stack_a);
	sort_small_stack(stacks);
	// display_stack(stacks->stack_a);
	return (0);
}

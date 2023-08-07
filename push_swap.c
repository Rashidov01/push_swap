/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:06:13 by arashido          #+#    #+#             */
/*   Updated: 2023/08/07 21:04:20 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	t_list		*tmp;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	stacks->stack_a = NULL;
	if (argc < 2)
	{
		write(2, "less parameter\n", 16);
		exit(1);
	}
	error(argc, argv, &(stacks->stack_a));
	tmp = stacks->stack_a;
	while (tmp)
	{
		printf("num: %d\n", tmp->content);
		tmp = tmp->next;
	}
}

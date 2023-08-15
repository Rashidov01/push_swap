/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:06:13 by arashido          #+#    #+#             */
/*   Updated: 2023/08/15 13:09:36 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_list(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

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
	display_stack(stacks->stack_a);
	sort_3(&stacks->stack_a);
	display_stack(stacks->stack_a);
	ft_free_list(stacks->stack_a);
	free(stacks);
	return (0);
}

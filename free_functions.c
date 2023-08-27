/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:47:47 by arashido          #+#    #+#             */
/*   Updated: 2023/08/18 14:42:06 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **str)
{
	int	idx;

	if (str == NULL)
		return ;
	idx = 0;
	while (str[idx] != NULL)
	{
		free(str[idx]);
		idx++;
	}
	free(str);
}

void	free_stack(t_stacks *stack)
{
	ft_free_list(stack->stack_a);
	ft_free_list(stack->stack_b);
	free(stack);
}

void	free_all(t_stacks *stack)
{
	free_stack(stack);
	write(2, "Error\n", 6);
	exit(1);
}

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

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (array)
	{
		while (array[i])
			free(array[i++]);
		free(array);
	}
}

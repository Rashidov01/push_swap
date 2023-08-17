/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:05:31 by arashido          #+#    #+#             */
/*   Updated: 2023/08/17 21:36:20 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_empty_quote(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (((unsigned char)str[i]) != ' ')
			return (false);
		i++;
	}
	return (true);
}

bool	has_empty_quotes(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_empty_quote(argv[i]))
			return (true);
		i++;
	}
	return (false);
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

void	sign_check(char **split, t_stacks *stack)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (check_digit_str(split[i]) == 0)
		{
			write(2, "Error\n", 6);
			free_split(split);
			free_stack(stack);
			exit(1);
		}
		i++;
	}
}

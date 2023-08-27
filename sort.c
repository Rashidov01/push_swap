/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:39:01 by arashido          #+#    #+#             */
/*   Updated: 2023/08/27 13:36:08 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bullshit(char **og, char **cpa, t_stacks *st)
{
	write(2, "Error\n", 6);
	free_split(og);
	free_split(cpa);
	ft_free_list(st->stack_a);
	ft_free_list(st->stack_b);
	free(st);
	exit(1);
}

char	**ft_sort(char **copy)
{
	int		i;
	int		j;
	char	*temp;
	int		len;

	len = ft_array_len(copy);
	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_atoi(copy[i]) > ft_atoi(copy[j]))
			{
				temp = copy[i];
				copy[i] = copy[j];
				copy[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (copy);
}

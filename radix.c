/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 20:23:05 by arashido          #+#    #+#             */
/*   Updated: 2023/08/17 13:36:23 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_sort(char **copy)
{
	int		i;
	int		j;
	char	*temp;
	int		len;

	len = ft_strlen(*copy);
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

char	**replace_with_index(char **og_array)
{
	int		i;
	int		j;
	char	**copy_array;

	copy_array = dup_array(og_array);
	copy_array = ft_sort(copy_array);
	i = 0;
	while (og_array[i])
	{
		j = 0;
		while (copy_array[j])
		{
			if (ft_atoi(og_array[i]) == ft_atoi(copy_array[j]))
			{
				free(og_array[i]);
				og_array[i] = ft_itoa(j);
				break ;
			}
			j++;
		}
		i++;
	}
	return (copy_array);
}

void	big_sort(t_stacks *stacks)
{
	int		bits;
	t_list	*temp;
	int		length;
	int		i;
	int		j;

	i = 0;
	temp = stacks->stack_a;
	length = ft_lstsize(temp) - 1;
	bits = total_bits(stacks->stack_a);
	while (i < bits)
	{
		j = -1;
		while (++j <= length)
		{
			temp = stacks->stack_a;
			if (!(temp->content >> i & 1))
				ft_pb(stacks);
			else
				ft_ra(&(stacks->stack_a));
		}
		while (ft_lstsize(stacks->stack_b) != 0)
			ft_pa(stacks);
		i++;
	}
}

int	total_bits(t_list *stack_a)
{
	t_list	*temp;
	int		max;
	int		total_bits;

	temp = stack_a;
	max = temp->content;
	total_bits = 0;
	while (temp)
	{
		if (temp->content > max)
			max = temp->content;
		temp = temp->next;
	}
	while ((max >> total_bits) != 0)
		total_bits++;
	return (total_bits);
}

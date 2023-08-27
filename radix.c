/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 20:23:05 by arashido          #+#    #+#             */
/*   Updated: 2023/08/26 18:40:07 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_norm2(int i, int j, char **og)
{
	free(og[i]);
	og[i] = ft_itoa(j);
}

char	**og_calc(char **og, char **cpa, t_stacks *st, long long *num)
{
	num[3] = 0;
	while (og[num[3]])
	{
		num[4] = 0;
		while (cpa[num[4]])
		{
			num[0] = ft_atoi3(og[num[3]], st, cpa, og);
			num[1] = ft_atoi3(cpa[num[4]], st, cpa, og);
			if ((num[0] >= INT_MIN && num[0] <= INT_MAX) || (num[1] >= INT_MIN
					&& num[1] <= INT_MAX))
			{
				if (num[0] == num[1])
				{
					ft_norm2(num[3], num[4], og);
					break ;
				}
			}
			else
				bullshit(og, cpa, st);
			num[4]++;
		}
		num[3]++;
	}
	return (og);
}

char	**replace_with_index(char **og, t_stacks *st)
{
	char		**cpa;
	long long	num[4];

	cpa = dup_array(og);
	cpa = ft_sort(cpa);
	og = og_calc(og, cpa, st, num);
	free_array(cpa);
	return (og);
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
	length = ft_lstsize(temp);
	bits = total_bits(stacks->stack_a);
	while (i < bits)
	{
		j = -1;
		while (++j < length)
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

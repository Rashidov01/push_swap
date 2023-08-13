/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 20:23:05 by arashido          #+#    #+#             */
/*   Updated: 2023/08/13 18:34:00 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Goal -- replaces the numbers with their index
// e.g -- 4 7 0 2 -9  --> 3 4 1 2 0
// first you need to create sort the numbers
// -9 0 2 4 7 --> this is a copy of the indexes
// then you compare the sorted copy with original index.

// char	*make_sort_copy(char *str)
// {
// 	char	*copy;

// 	copy = (char *)malloc((sizeof(char *) * (ft_strlen(str) + 1)));
// 	return (copy);
// }
// void	ft_copy(int len, char **new_args, char **copy)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < len)
// 	{
// 		j = 0;
// 		while (j < len)
// 		{
// 			if (ft_atoi(new_args[i]) == ft_atoi(copy[j]))
// 			{
// 				free(new_args[i]);
// 				new_args[i] = ft_itoa(j);
// 				break ;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }
int	replace_with_index(char *og_str, char *copy_str)
{
	int	i;
	int	j;

	i = 0;
	while (og_str[i])
	{
		j = 0;
		while (copy_str[j])
		{
			if (ft_atoi(og_str[i]) == ft_atoi(copy_str[j]))
			{
                
				free(og_str[i]);
				og_str[i] = ft_itoa(j);
				break ;
			}
			j++;
		}
		i++;
	}
}

void	big_sort(t_node **A, t_node **b)
{
	int		bits;
	t_node	*temp;
	int		length;
	int		i;
	int		j;

	i = 0;
	temp = *A;
	length = ft_lstsize(temp) - 1;
	bits = total_bits(A);
	while (i < bits)
	{
		j = -1;
		while (j++ <= length)
		{
			temp = *A;
			if (!(temp->data >> i & 1))
				pb(A, b);
			else
				ra(A);
		}
		while (ft_lstsize(*b) != 0)
			pa(A, b);
		i++;
	}
}

int	total_bits(t_node **A)
{
	t_node	*temp;
	int		max;
	int		total_bits;

	temp = *A;
	max = temp->data;
	total_bits = 0;
	while (temp)
	{
		if (temp->data > max)
			max = temp->data;
		temp = temp->next;
	}
	while ((max >> total_bits) != 0)
		total_bits++;
	return (total_bits);
}

// then you can call radix:

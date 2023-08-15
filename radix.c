/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 20:23:05 by arashido          #+#    #+#             */
/*   Updated: 2023/08/13 23:01:29 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Goal -- replaces the numbers with their index
// e.g -- 4 7 0 2 -9  --> 3 4 1 2 0
// first you need to create sort the numbers
// -9 0 2 4 7 --> this is a copy of the indexes
// then you compare the sorted copy with original index.

// PART 1 -> make copy of string;
// char	*make_copy(char *str)
// {
// 	char	*copy;

// 	copy = (char *)malloc((sizeof(char *) * (ft_strlen(str) + 1)));
// 	copy = ft_strcpy(copy, str);
// 	return (copy);
// }

// //PART 2 --> sort the copy using selection sort
// void	ft_sort(char **copy)
// {
// 	int		i;
// 	int		j;
// 	char	*temp;
// 	int len;

// 	len = ft_strlen(copy);
// 	i = 0;
// 	while (i < len - 1)
// 	{
// 		j = i + 1;
// 		while (j < len)
// 		{
// 			if (ft_atoi(copy[i]) > ft_atoi(copy[j]))
// 			{
// 				temp = copy[i];
// 				copy[i] = copy[j]; //ft_swap
// 				copy[j] = temp;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

// // PART 3 --> Replace orignal string with index value
// int	replace_with_index(char *og_str, char *copy_str)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (og_str[i])
// 	{
// 		j = 0;
// 		while (copy_str[j])
// 		{
// 			if (ft_atoi(og_str[i]) == ft_atoi(copy_str[j]))
// 			{
// 				free(og_str[i]);
// 				og_str[i] = ft_itoa(j);
// 				break ;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

// PART 4 -> stupid radix
// void	big_sort(t_stacks *stacks)
// {
// 	int		bits;
// 	t_node	*temp;
// 	int		length;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	temp = *A;
// 	length = ft_lstsize(temp) - 1;
// 	bits = total_bits(A);
// 	while (i < bits)
// 	{
// 		j = -1;
// 		while (j++ <= length)
// 		{
// 			temp = *A;
// 			if (!(temp->data >> i & 1))
// 				pb(A, b);
// 			else
// 				ra(A);
// 		}
// 		while (ft_lstsize(*b) != 0)
// 			pa(A, b);
// 		i++;
// 	}
// }

// int	total_bits(t_node **A)
// {
// 	t_node	*temp;
// 	int		max;
// 	int		total_bits;

// 	temp = *A;
// 	max = temp->data;
// 	total_bits = 0;
// 	while (temp)
// 	{
// 		if (temp->data > max)
// 			max = temp->data;
// 		temp = temp->next;
// 	}
// 	while ((max >> total_bits) != 0)
// 		total_bits++;
// 	return (total_bits);
// }

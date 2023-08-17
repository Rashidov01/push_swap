/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:22:08 by arashido          #+#    #+#             */
/*   Updated: 2023/08/17 14:27:41 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_array_len(char **str)
{
	int	str_rows;

	str_rows = 0;
	while (str[str_rows] != NULL)
		str_rows++;
	return (str_rows);
}

char	**dup_array(char **src)
{
	int		num_words;
	char	**dest;
	int		i;

	num_words = ft_array_len(src);
	dest = (char **)malloc((num_words + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	i = -1;
	while (++i < num_words)
		dest[i] = ft_strdup(src[i]);
	dest[i] = NULL;
	return (dest);
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

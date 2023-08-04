#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*stack;
	int	size;
}		t_stack;

bool	check_duplicate(char **argv);
void	ft_free_arr(char **p);
char	*join_argv(char **argv);
#endif
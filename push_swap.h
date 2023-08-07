#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libs/libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	t_list	*stack_a;
	t_list	*stack_b;
}			t_stacks;

bool		check_duplicate(char **argv);
bool		is_empty_quote(const char *str);
bool		has_empty_quotes(int argc, char **argv);
int			error(int argc, char **argv, t_list **stack_a);
size_t		ft_strspn(const char *str, const char *charset);
void		ft_free_arr(char **p);
char		*join_argv(char **argv);
bool		has_empty_quotes(int argc, char **argv);
int			ft_strcmp(const char *s1, const char *s2);
char		*join_argv(char **argv);
char		**split_argv(char **argv);
#endif
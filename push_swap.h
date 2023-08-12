/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 13:45:15 by arashido          #+#    #+#             */
/*   Updated: 2023/08/12 14:16:12 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libs/libft/libft.h"
# include "./libs/printf/ft_printf.h"
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
	int		size;
	int		*array;
}			t_stacks;

bool		check_duplicate(char **argv);
bool		is_empty_quote(const char *str);
bool		has_empty_quotes(int argc, char **argv);
size_t		ft_strspn(const char *str, const char *charset);
int			ft_strcmp(const char *s1, const char *s2);
int			error(int argc, char **argv, t_list **stack_a);
int			check_digit_str(const char *str);
char		*join_argv(char **argv);
char		*join_argv(char **argv);
char		**split_argv(char **argv);
void		ft_free_arr(char **p);
void		if_sorted(t_stacks *stacks);

// operations
void		ft_sa(t_list **a);
void		ft_sb(t_list **b);
void		ft_ss(t_list **a, t_list **b);

void		ft_ra(t_list **a);
void		ft_rb(t_list **b);
void		ft_rr(t_list **a, t_list **b);

void		ft_rra(t_list **a);
void		ft_rrb(t_list **b);
void		ft_rrr(t_list **a, t_list **b);

void		ft_pb(t_stacks *stacks);
void		ft_pa(t_stacks *stacks);
#endif
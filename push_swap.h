/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 13:45:15 by arashido          #+#    #+#             */
/*   Updated: 2023/08/17 14:47:15 by arashido         ###   ########.fr       */
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
	t_list		*stack_a;
	t_list		*stack_b;
}				t_stacks;

// parsing
bool			check_duplicate(char **argv);
bool			is_empty_quote(const char *str);
bool			has_empty_quotes(int argc, char **argv);
size_t			ft_strspn(const char *str, const char *charset);
int				ft_strcmp(const char *s1, const char *s2);
int				error(int argc, char **argv, t_stacks *stacks);
int				check_digit_str(const char *str);
char			*join_argv(char **argv);
char			*join_argv(char **argv);
char			**split_argv(char **argv);
void			ft_free_list(t_list *lst);
int				is_sorted(t_list *stack_a);
int				get_min_pos(t_list *stack_a, int min);

// operations
void			ft_sa(t_list **a);
void			ft_sb(t_list **b);
void			ft_ss(t_list **a, t_list **b);

void			ft_ra(t_list **a);
void			ft_rb(t_list **b);
void			ft_rr(t_list **a, t_list **b);

void			ft_rra(t_list **a);
void			ft_rrb(t_list **b);
void			ft_rrr(t_list **a, t_list **b);

void			ft_pb(t_stacks *stacks);
void			ft_pa(t_stacks *stacks);

// radix sort
void			display_stack(t_list *a);
int				find_the_smallest(t_list *stack_a);
void			sort_2(t_list **stack_a);
void			sort_3(t_list **stack_a);
void			sort_4(t_stacks *stacks);
void			sort_5(t_stacks *stacks);
void			big_sort(t_stacks *stacks);
int				total_bits(t_list *stack_a);
char			**ft_sort(char **copy);
size_t			ft_strcpy(char *dst, const char *src);
char			**replace_with_index(char **og_array);
long long int	ft_atoi2(const char *str, t_stacks *stack, char **split);
void			free_split(char **str);
void			ft_free_list(t_list *lst);
char			**dup_array(char **src);
void			free_array(char **array);
void			free_stack(t_stacks *stack);
void			free_all(t_stacks *stack);
#endif
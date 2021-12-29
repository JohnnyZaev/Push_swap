/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:38:01 by gvarys            #+#    #+#             */
/*   Updated: 2021/12/29 11:52:03 by gvarys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define TRUE 1
# define FALSE 0

# include <unistd.h>
# include <stdlib.h>
# include "/Users/gvarys/Desktop/push_swap/Libft/libft.h"

# include <stdio.h> //DELETE THIS PLS

typedef struct s_stack
{
	int				content;
	int				step;
	int				flag;
	struct s_stack	*next;
}					t_stack;

typedef struct s_push_swap
{
	int			*pre_sorted;
	int			a_numbers;
	int			b_numbers;
	int			min;
	int			max;
	int			mid;
	int			max_a;
	id_t		last_index;
	id_t		element;
	t_stack		*a;
	t_stack		*b;
}				t_push_swap;

void	init_push_swap(t_push_swap *p_s);
int		argv_is_valid(int argc, char **argv);
int		duplicate_check(int argc, char **argv);
void	full_stacks(int argc, char **argv, t_push_swap *p_s);
void	free_stack(t_push_swap *p_s);
void	quicksort(int *array, int low, int high);
void	swap_a(t_stack *a, int flag);
void	swap_b(t_stack *b, int flag);
void	swap_ab(t_push_swap *p_s);
void	push_a(t_push_swap *p_s);
void	push_b(t_push_swap *p_s);
void	rotate_a(t_stack **a, int flag);
void	rotate_b(t_stack **b, int flag);
void	rotate_all(t_push_swap *p_s);
void	reverse_rotate_a(t_stack **a, int flag);
void	reverse_rotate_b(t_stack **b, int flag);
void	reverse_rotate_all(t_push_swap *p_s);
void	mini_sort(t_push_swap *p_s);
void	medium_sort(t_push_swap *p_s);
void	max_a(t_push_swap *p_s, t_stack *a);
int		sorted(t_stack *a);

#endif
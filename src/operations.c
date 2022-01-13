/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:34:56 by gvarys            #+#    #+#             */
/*   Updated: 2022/01/13 11:21:57 by gvarys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *a, int flag)
{
	int	temp;

	if (!a || !a->next)
		return ;
	temp = a->content;
	a->content = a->next->content;
	a->next->content = temp;
	if (flag == TRUE)
		write(1, "sa\n", 3);
}

void	swap_b(t_stack *b, int flag)
{
	int	temp;

	if (!b || !b->next)
		return ;
	temp = b->content;
	b->content = b->next->content;
	b->next->content = temp;
	if (flag == TRUE)
		write(1, "sb\n", 3);
}

void	swap_ab(t_push_swap *p_s, int flag)
{
	swap_a(p_s->a, FALSE);
	swap_b(p_s->b, FALSE);
	if (flag == TRUE)
		write(1, "ss\n", 3);
}

void	push_a(t_push_swap *p_s, int flag)
{
	t_stack	*temp;

	if (!p_s->b)
		return ;
	temp = p_s->b;
	p_s->b = p_s->b->next;
	temp->next = p_s->a;
	p_s->a = temp;
	p_s->a_numbers += 1;
	p_s->b_numbers -= 1;
	if (flag == TRUE)
		write(1, "pa\n", 3);
}

void	push_b(t_push_swap *p_s, int flag)
{
	t_stack	*temp;

	if (!p_s->a)
		return ;
	temp = p_s->a;
	p_s->a = p_s->a->next;
	temp->next = p_s->b;
	p_s->b = temp;
	p_s->b_numbers += 1;
	p_s->a_numbers -= 1;
	if (flag == TRUE)
		write(1, "pb\n", 3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 17:42:49 by gvarys            #+#    #+#             */
/*   Updated: 2022/01/10 17:05:47 by gvarys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack **a, int flag)
{
	t_stack	*start;
	t_stack	*save;
	t_stack	*finish;

	if ((*a) == NULL || ((*a)->next) == NULL)
		return ;
	start = *a;
	finish = *a;
	while (finish->next->next != NULL)
		finish = finish->next;
	save = finish->next;
	finish->next = NULL;
	save->next = start;
	*a = save;
	if (flag == TRUE)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack **b, int flag)
{
	t_stack	*start;
	t_stack	*save;
	t_stack	*finish;

	if ((*b) == NULL || ((*b)->next) == NULL)
		return ;
	start = *b;
	finish = *b;
	while (finish->next->next != NULL)
		finish = finish->next;
	save = finish->next;
	finish->next = NULL;
	save->next = start;
	*b = save;
	if (flag == TRUE)
		write(1, "rrb\n", 4);
}

void	reverse_rotate_all(t_push_swap *p_s, int flag)
{
	reverse_rotate_a(&p_s->a, FALSE);
	reverse_rotate_b(&p_s->b, FALSE);
	p_s->steps_b--;
	if (flag == TRUE)
		write(1, "rrr\n", 4);
}

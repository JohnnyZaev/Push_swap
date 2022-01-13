/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 17:05:34 by gvarys            #+#    #+#             */
/*   Updated: 2022/01/10 17:05:09 by gvarys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **a, int flag)
{
	t_stack	*start;
	t_stack	*save;
	t_stack	*finish;

	if ((*a) == NULL || ((*a)->next) == NULL)
		return ;
	save = *a;
	start = (*a)->next;
	finish = *a;
	while (finish->next != NULL)
		finish = finish->next;
	save->next = NULL;
	finish->next = save;
	*a = start;
	if (flag == TRUE)
		write(1, "ra\n", 3);
}

void	rotate_b(t_stack **b, int flag)
{
	t_stack	*start;
	t_stack	*save;
	t_stack	*finish;

	if ((*b) == NULL || ((*b)->next) == NULL)
		return ;
	save = *b;
	start = (*b)->next;
	finish = *b;
	while (finish->next != NULL)
		finish = finish->next;
	save->next = NULL;
	finish->next = save;
	*b = start;
	if (flag == TRUE)
		write(1, "rb\n", 3);
}

void	rotate_all(t_push_swap *p_s, int flag)
{
	rotate_a(&p_s->a, FALSE);
	rotate_b(&p_s->b, FALSE);
	p_s->steps_b--;
	if (flag == TRUE)
		write(1, "rr\n", 3);
}

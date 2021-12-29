/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:46:41 by gvarys            #+#    #+#             */
/*   Updated: 2021/12/29 11:23:26 by gvarys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	max_a(t_push_swap *p_s, t_stack *a)
{
	p_s->max_a = a->content;
	while (a)
	{
		if (a->content > p_s->max_a)
			p_s->max_a = a->content;
		a = a->next;
	}
}

void	mini_sort(t_push_swap *p_s)
{
	max_a(p_s, p_s->a);
	if (p_s->a_numbers > 1)
	{
		if (p_s->a_numbers == 2)
		{
			if (p_s->a->content > p_s->a->next->content)
				swap_a(p_s->a, TRUE);
		}
		if (p_s->a_numbers == 3)
		{
			if (p_s->a->content == p_s->max_a)
				rotate_a(&p_s->a, TRUE);
			if ((p_s->a->next->content) == p_s->max_a)
				reverse_rotate_a(&p_s->a, TRUE);
			if ((p_s->a->content) > (p_s->a->next->content))
				swap_a(p_s->a, TRUE);
		}
	}
}

void	medium_sort(t_push_swap *p_s)
{
	while (p_s->b_numbers != 2)
	{
		if (p_s->a->content == p_s->min || p_s->a->content == p_s->max)
			push_b(p_s);
		else
			rotate_a(&p_s->a, TRUE);
	}
	mini_sort(p_s);
	push_a(p_s);
	push_a(p_s);
	if (p_s->a->content == p_s->max)
		rotate_a(&p_s->a, TRUE);
	else
	{
		swap_a(p_s->a, TRUE);
		rotate_a(&p_s->a, TRUE);
	}
}

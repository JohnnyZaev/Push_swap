/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:29:16 by gvarys            #+#    #+#             */
/*   Updated: 2022/01/10 17:05:59 by gvarys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	big_swap(t_push_swap *p_s)
{
	while (p_s->steps_a > 0)
	{
		if (p_s->steps_b > 0 && p_s->dest_b == 1 && p_s->dest_a == 1)
			rotate_all(p_s, TRUE);
		else if (p_s->dest_a == 1)
			rotate_a(&p_s->a, TRUE);
		else if (p_s->steps_b > 0 && p_s->dest_b != 1 && p_s->dest_a != 1)
			reverse_rotate_all(p_s, TRUE);
		else
			reverse_rotate_a(&p_s->a, TRUE);
		p_s->steps_a--;
	}
	while (p_s->steps_b > 0)
	{
		if (p_s->dest_b == 1)
			rotate_b(&p_s->b, TRUE);
		else
			reverse_rotate_b(&p_s->b, TRUE);
		p_s->steps_b--;
	}
	push_a(p_s, TRUE);
}

static void	find_min_steps(t_push_swap *p_s)
{
	int		min;
	t_stack	*temp_a;
	t_stack	*temp_b;

	min = -1;
	temp_a = p_s->a;
	temp_b = p_s->b;
	while (p_s->b)
	{
		min = find_min(p_s, min);
		p_s->a = temp_a;
		p_s->b = p_s->b->next;
	}
	p_s->b = temp_b;
}

static void	step_counter(t_stack *stack, int numbers)
{
	int		i;
	int		median;
	t_stack	*temp;

	i = 0;
	median = numbers / 2;
	temp = stack;
	while (i <= median)
	{
		temp->step = i;
		temp->flag = 1;
		temp = temp->next;
		i++;
	}
	if (numbers % 2 == 0)
		i--;
	while (--i > 0)
	{
		temp->step = i;
		temp->flag = -1;
		temp = temp->next;
	}
}

static void	steps_sort(t_push_swap *p_s)
{
	while (p_s->b_numbers != 0)
	{
		p_s->steps_a = -1;
		p_s->steps_b = -1;
		p_s->dest_a = 0;
		p_s->dest_b = 0;
		step_counter(p_s->a, p_s->a_numbers);
		step_counter(p_s->b, p_s->b_numbers);
		find_min_steps(p_s);
		big_swap(p_s);
	}
	if ((min_count(p_s->a, p_s->min)) > p_s->a_numbers / 2)
	{
		while (p_s->a->content != p_s->min)
			reverse_rotate_a(&p_s->a, TRUE);
	}
	else
	{
		while (p_s->a->content != p_s->min)
			rotate_a(&p_s->a, TRUE);
	}
}

void	big_sort(t_push_swap *p_s)
{
	while (p_s->a_numbers > 2)
	{
		if (p_s->a->content != p_s->min && p_s->a->content != p_s->max)
		{
			push_b(p_s, TRUE);
			if (p_s->a->content > p_s->mid)
				rotate_b(&p_s->b, TRUE);
		}
		else
			rotate_a(&p_s->a, TRUE);
	}
	if (p_s->a->content < p_s->a->next->content)
		swap_a(p_s->a, TRUE);
	push_a(p_s, TRUE);
	steps_sort(p_s);
}

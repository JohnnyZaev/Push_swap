/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:05:16 by gvarys            #+#    #+#             */
/*   Updated: 2022/01/10 13:58:11 by gvarys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	have_smaller(t_stack *stack, int temp, int content)
{
	int		result;
	t_stack	*save;

	save = stack;
	result = 0;
	while (save && result == 0)
	{
		if (save->content < temp && save->content > content)
			result = 1;
		save = save->next;
	}
	return (result);
}

static void	half_find_min(t_push_swap *p_s, t_stack *b, int *actions, int *temp)
{
	while (p_s->a)
	{
		*temp = p_s->a->content;
		if (b->content > p_s->a->content)
		{
			*actions += 1;
			if (b->content < p_s->a->next->content)
				break ;
			p_s->a = p_s->a->next;
		}
		else
			break ;
	}
	if (have_smaller(p_s->a, *temp, b->content) == 1)
	{
		while (p_s->a)
		{
			if (p_s->a->content < *temp && p_s->a->content > b->content)
				break ;
			*actions += 1;
			p_s->a = p_s->a->next;
		}
	}
}

int	find_min(t_push_swap *p_s, int min)
{
	t_stack	*temp_b;
	int		result;
	int		temp;
	int		actions;

	temp_b = p_s->b;
	temp = 0;
	actions = 0;
	half_find_min(p_s, temp_b, &actions, &temp);
	if (p_s->a->flag == -1)
		actions = p_s->a_numbers - actions;
	if (min == -1 || (actions + temp_b->step) < min)
	{
		p_s->dest_a = p_s->a->flag;
		p_s->dest_b = temp_b->flag;
		p_s->steps_a = actions;
		p_s->steps_b = temp_b->step;
		result = actions + temp_b->step;
	}
	else
		result = min;
	return (result);
}

int	min_count(t_stack *stack, int min)
{
	int	result;

	result = 0;
	while (stack)
	{
		if (stack->content == min)
			break ;
		stack = stack->next;
		result++;
	}
	return (result);
}

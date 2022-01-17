/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 11:56:32 by gvarys            #+#    #+#             */
/*   Updated: 2022/01/17 10:06:19 by gvarys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_push_swap *p_s)
{
	t_stack	*temp;

	while (p_s->a != NULL)
	{
		temp = p_s->a;
		p_s->a = p_s->a->next;
		free(temp);
	}
	while (p_s->b != NULL)
	{
		temp = p_s->b;
		p_s->b = p_s->b->next;
		free(temp);
	}
}

static void	start_stack(t_push_swap *p_s)
{
	int		i;
	t_stack	*a;
	t_stack	*first_a;

	i = 0;
	a = (t_stack *)malloc(sizeof(t_stack));
	if (!a)
		exit(1);
	first_a = a;
	a->content = p_s->pre_sorted[i];
	while (++i != p_s->last_index + 1)
	{
		a->next = malloc(sizeof(t_stack));
		if (!a->next)
		{
			free_stack(p_s);
			exit (1);
		}
		a = a->next;
		a->content = p_s->pre_sorted[i];
	}
	a->next = NULL;
	p_s->a = first_a;
	p_s->b = NULL;
}

void	full_stacks(int argc, char **argv, t_push_swap *p_s)
{
	p_s->pre_sorted = malloc(sizeof(int) * (argc - 1));
	if (!p_s->pre_sorted)
		exit(1);
	p_s->last_index = argc - 2;
	while (--argc)
	{
		p_s->pre_sorted[argc - 1] = ft_atoi(argv[argc]);
	}
	start_stack(p_s);
	quicksort(p_s->pre_sorted, 0, p_s->last_index);
	p_s->min = p_s->pre_sorted[0];
	p_s->max = p_s->pre_sorted[p_s->last_index];
	p_s->mid = p_s->pre_sorted[p_s->last_index] / 2;
	p_s->a_numbers = p_s->last_index + 1;
	p_s->b_numbers = 0;
}

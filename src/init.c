/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:36:57 by gvarys            #+#    #+#             */
/*   Updated: 2022/01/13 12:49:39 by gvarys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_push_swap(t_push_swap *p_s)
{
	p_s->b_numbers = 0;
	p_s->a_numbers = 0;
	p_s->min = 0;
	p_s->max = 0;
	p_s->mid = 0;
}

int	sorted(t_push_swap *p_s)
{
	int		i;
	int		temp;
	t_stack	*save;

	i = 0;
	save = p_s->a;
	while (i < (p_s->a_numbers - 1))
	{
		temp = p_s->a->content;
		p_s->a = p_s->a->next;
		if (temp > p_s->a->content)
		{
			p_s->a = save;
			return (0);
		}
		i++;
	}
	p_s->a = save;
	return (1);
}

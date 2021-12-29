/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:37:57 by gvarys            #+#    #+#             */
/*   Updated: 2021/12/29 11:51:19 by gvarys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_stack *a)
{
	while (a->next)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

static void	sort_option(t_push_swap *p_s)
{
	if (sorted(p_s->a))
		return ;
	if (p_s->a_numbers <= 3)
		mini_sort(p_s);
	else if (p_s->a_numbers <= 5)
		medium_sort(p_s);
}

static void	push_swap(int argc, char **argv)
{
	t_push_swap	*p_s;

	p_s = (t_push_swap *)malloc(sizeof(t_push_swap));
	if (!p_s)
		exit(0);
	init_push_swap(p_s);
	if (argv_is_valid(argc, argv) && duplicate_check(argc, argv))
	{
		full_stacks(argc, argv, p_s);
		sort_option(p_s);
	}
	free(p_s);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		push_swap(argc, argv);
	}
	return (0);
}

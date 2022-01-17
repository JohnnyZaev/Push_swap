/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:37:57 by gvarys            #+#    #+#             */
/*   Updated: 2022/01/17 10:06:52 by gvarys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_option(t_push_swap *p_s)
{
	if (sorted(p_s))
		return ;
	if (p_s->a_numbers <= 3)
		mini_sort(p_s);
	else if (p_s->a_numbers <= 5)
		medium_sort(p_s);
	else
		big_sort(p_s);
}

static void	push_swap(int argc, char **argv)
{
	t_push_swap	*p_s;

	p_s = (t_push_swap *)malloc(sizeof(t_push_swap));
	if (!p_s)
		exit(1);
	init_push_swap(p_s);
	if (argv_is_valid(argc, argv) && duplicate_check(argc, argv))
	{
		full_stacks(argc, argv, p_s);
		sort_option(p_s);
		free_stack(p_s);
		free(p_s->pre_sorted);
	}
	else
		ft_putstr_fd("Error\n", 1);
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

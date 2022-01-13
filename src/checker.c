/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:12:04 by gvarys            #+#    #+#             */
/*   Updated: 2022/01/13 13:36:36 by gvarys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}

static void	use_operations(t_push_swap *p_s, char *line)
{
	if (ft_strncmp(line, "sa", 2) == FALSE && !line[3])
		swap_a(p_s->a, FALSE);
	else if (ft_strncmp(line, "sb", 2) == FALSE && !line[3])
		swap_b(p_s->b, FALSE);
	else if (ft_strncmp(line, "ss", 2) == FALSE && !line[3])
		swap_ab(p_s, FALSE);
	else if (ft_strncmp(line, "pa", 2) == FALSE && !line[3])
		push_a(p_s, FALSE);
	else if (ft_strncmp(line, "pb", 2) == FALSE && !line[3])
		push_b(p_s, FALSE);
	else if (ft_strncmp(line, "rra", 3) == FALSE && !line[4])
		reverse_rotate_a(&p_s->a, FALSE);
	else if (ft_strncmp(line, "rrb", 3) == FALSE && !line[4])
		reverse_rotate_b(&p_s->b, FALSE);
	else if (ft_strncmp(line, "rrr", 3) == FALSE && !line[4])
		reverse_rotate_all(p_s, FALSE);
	else if (ft_strncmp(line, "ra", 2) == FALSE && !line[3])
		rotate_a(&p_s->a, FALSE);
	else if (ft_strncmp(line, "rb", 2) == FALSE && !line[3])
		rotate_b(&p_s->b, FALSE);
	else if (ft_strncmp(line, "rr", 2) == FALSE && !line[3])
		rotate_all(p_s, FALSE);
	else
		print_error();
}

static void	checker_work(t_push_swap *p_s)
{
	char	*line;

	line = NULL;
	line = get_next_line(0);
	while (line)
	{
		use_operations(p_s, line);
		free(line);
		line = NULL;
		line = get_next_line(0);
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
}

int	main(int argc, char **argv)
{
	t_push_swap	*p_s;

	p_s = malloc(sizeof(t_push_swap));
	if (!p_s)
		exit(1);
	if (argc > 1)
	{
		init_push_swap(p_s);
		if (argv_is_valid(argc, argv) && duplicate_check(argc, argv))
		{
			full_stacks(argc, argv, p_s);
			checker_work(p_s);
			if ((sorted(p_s)) && p_s->b_numbers == 0)
				write(1, "OK\n", 3);
			else
				write(1, "KO\n", 3);
			free_stack(p_s);
			free(p_s->pre_sorted);
		}
		else
			ft_putstr_fd("Error\n", 1);
	}
	free(p_s);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:36:32 by gvarys            #+#    #+#             */
/*   Updated: 2021/12/29 13:39:47 by gvarys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	for_d_c(int *check, int len)
{
	int	i;
	int	j;

	i = 0;
	while (check[i] != check[len])
	{
		j = i + 1;
		while (check[j])
		{
			if (check[i] == check[j])
			{
				return (FALSE);
			}
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	argv_is_valid(int argc, char **argv)
{
	int	i;

	while (argc-- != 1)
	{
		i = 0;
		if (argv[argc][i] == '-')
			i++;
		while (argv[argc][i])
		{
			if (!(ft_isdigit(argv[argc][i])))
				return (FALSE);
			i++;
		}
	}
	return (TRUE);
}

int	duplicate_check(int argc, char **argv)
{
	int	*check;
	int	i;
	int	len;

	check = malloc(sizeof(int) * --argc);
	if (!check)
		return (FALSE);
	i = 0;
	len = argc - 1;
	while (argc)
	{
		check[i] = ft_atoi(argv[argc]);
		argc--;
		i++;
	}
	if (for_d_c(check, len))
	{
		free(check);
		return (TRUE);
	}
	else
	{
		free(check);
		return (FALSE);
	}
}

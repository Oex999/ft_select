/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 08:40:46 by oexall            #+#    #+#             */
/*   Updated: 2016/07/14 15:10:49 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void	ft_clear_list(t_list **begin_list)
{
	t_list	*lst;
	t_list	*tmp;

	lst = *begin_list;
	if (lst)
	{
		while (lst)
		{
			if (lst->value)
				free(lst->value);
			tmp = lst->next;
			lst->next = NULL;
			free(lst);
			lst = tmp;
		}
	}
}

int		ft_list(t_main *all, char **argv)
{
	ft_clear_screen();
	ft_args_to_list(argv, all);
	ft_print_select(all);
	while (1)
	{
		if (ft_keyhook(all) == -1)
			return (0);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_main	all;

	all.lst = NULL;
	all.cnt_lines = argc - 1;
	if (ft_init_term(&all) == 0)
		return (0);
	if (argc >= 2)
		ft_list(&all, argv);
	if (ft_end_term(&all) == 0)
		return (0);
	ft_clear_list(&all.lst);
	return (0);
}

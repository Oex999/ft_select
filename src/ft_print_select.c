/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_select.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 10:19:07 by oexall            #+#    #+#             */
/*   Updated: 2016/07/12 12:53:06 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	ft_print_underline(char *str)
{
	ft_putstr_fd("\e[4m", 2);
	ft_putendl_fd(str, 2);
	ft_putstr_fd("\e[0m", 2);
}

void	ft_print_inverse(char *str)
{
	ft_putstr_fd("\e[7m", 2);
	ft_putendl_fd(str, 2);
	ft_putstr_fd("\e[0m", 2);
}

void	ft_both(char *str)
{
	tputs(tgetstr("us", NULL), 1, ft_myputchar);
	ft_putstr_fd("\e[7;4m", 2);
	ft_putendl_fd(str, 2);
	ft_putstr_fd("\e[0m", 2);
	tputs(tgetstr("ue", NULL), 1, ft_myputchar);
}

void	ft_style(t_list *list)
{
	if (list->select == 1 && list->line == 0)
		ft_print_inverse(list->value);
	else if (list->line == 1 && list->select == 0)
		ft_print_underline(list->value);
	else if (list->line == 1 && list->select == 1)
		ft_both(list->value);
	else
		ft_putendl_fd(list->value, 2);
}

void	ft_print_select(t_main *all)
{
	t_list	*list;

	list = all->lst;
	while (list)
	{
		ft_style(list);
		list = list->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_select.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 09:04:39 by oexall            #+#    #+#             */
/*   Updated: 2016/07/14 15:05:44 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void	ft_deltab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i] != NULL)
		{
			free(tab[i]);
			tab[i] = NULL;
			i++;
		}
		free(tab);
	}
}

void		ft_select_item(t_main *all)
{
	t_list	*list;

	list = all->lst;
	while (list)
	{
		if (list->line == 1 && list->select == 0)
		{
			list->select = 1;
			ft_move_down(all);
			return ;
		}
		else if (list->line == 1 && list->select == 1)
		{
			list->select = 0;
			return ;
		}
		list = list->next;
	}
}

static int	ft_count_selection(t_main *all)
{
	int		count;
	t_list	*list;

	list = all->lst;
	count = 0;
	while (list)
	{
		if (list->select == 1)
			count++;
		list = list->next;
	}
	return (count);
}

void		ft_print_ret_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		if (tab[i + 1])
			ft_putchar(32);
		i++;
	}
}

int			ft_ret_tab(t_main *all)
{
	int		count;
	t_list	*list;

	all->ret_tab = NULL;
	count = ft_count_selection(all);
	list = all->lst;
	all->ret_tab = (char **)malloc(sizeof(char *) * (count + 1));
	list = all->lst;
	count = 0;
	while (list)
	{
		if (list->select == 1)
		{
			all->ret_tab[count] = ft_strdup(list->value);
			count++;
		}
		list = list->next;
	}
	all->ret_tab[count] = NULL;
	ft_print_ret_tab(all->ret_tab);
	ft_deltab(all->ret_tab);
	return (-1);
}

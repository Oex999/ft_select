/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 08:27:22 by oexall            #+#    #+#             */
/*   Updated: 2016/07/14 09:17:38 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <termcap.h>
# include <termios.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include "../libft/libft.h"

typedef enum		e_keys
{
	KEY_ESCAPE = 27,
	KEY_UP = 4283163,
	KEY_DOWN = 4348699,
	KEY_SPACE = 32,
	KEY_ENTER = 10,
	KEY_DEL = 127
}					t_keys;

typedef struct		s_list
{
	char			*value;
	int				len;
	int				select;
	int				line;
	struct s_list	*next;
}					t_list;

typedef struct		s_main
{
	struct termios	term;
	char			*name_term;
	t_list			*lst;
	int				cnt_lines;
	int				cnt_cols;
	int				nb_lines;
	int				nb_cols;
	int				enter;
	char			**ret_tab;
}					t_main;

int					ft_list(t_main *all, char **argv);

t_list				*ft_new_elem(char *value);
void				ft_push_elem_back(t_list **begin_list, char *value);
void				ft_args_to_list(char **args, t_main *all);

void				ft_print_underline(char *str);
void				ft_style(t_list *list);
void				ft_print_select(t_main *all);

int					ft_init_term(t_main *all);
int					ft_end_term(t_main *all);

t_main				*ft_new(t_main *all, int i);
void				ft_clear_screen(void);
int					ft_myputchar(int c);

int					ft_size(t_main *all);
void				ft_count_cols(t_main *all);
void				ft_resize(void);

int					ft_keyhook(t_main *all);
void				ft_move_down(t_main *all);
void				ft_move_up(t_main *all);

void				ft_select_item(t_main *all);
void				ft_print_ret_tab(char **tab);
int					ft_ret_tab(t_main *all);

void				ft_del_list(char *value, t_list **begin_list);
int					ft_del_line(t_main *all);

void				ft_signal(void);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 14:52:58 by mlarraq           #+#    #+#             */
/*   Updated: 2020/03/23 13:56:01 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct		s_filler
{
	int		i;
	int		flag;
	int		oper;
	int		oper2;
	int		player;
	int		my_char;
	int		int_my_char;
	int		opponent;
	int		int_opponent;
	char	*line;
	int		fwidth;
	int		fheight;
	int		pwidth;
	int		pheight;
	double	summ_of_numbers;
	int		count_cross;
	int		h_res;
	int		w_res;
	char	*field[1024];
	int		*intfield[1024];
	char	*piece[1024];
	int		*intpiece[1024];
	int		h1;
	int		w1;
	int		count;
	double	summ;
	int		co;
}					t_filler;

void				fill_numbers(t_filler *x);
int					placer_int(t_filler *x);
void				okantovka(t_filler *x);
void				find_player(t_filler *x);

#endif

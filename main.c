/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 14:54:12 by mlarraq           #+#    #+#             */
/*   Updated: 2020/05/21 12:15:27 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		read_pole(t_filler *x, char *line)
{
	x->i = 0;
	x->fheight = ft_atoi(line + 8);
	if (x->fheight > 1024)
		return (0);
	ft_strdel(&line);
	get_next_line(0, &line);
	ft_strdel(&line);
	while (x->i < x->fheight)
	{
		get_next_line(0, &line);
		x->field[x->i] = ft_strdup(line + 4);
		ft_strdel(&line);
		x->i++;
	}
	x->fwidth = ft_strlen(x->field[0]);
	return (1);
}

static void		read_piece(t_filler *x, char *line)
{
	x->i = 0;
	x->pheight = ft_atoi(line + 6);
	ft_strdel(&line);
	while (x->i < x->pheight)
	{
		get_next_line(0, &line);
		x->piece[x->i] = line;
		line = NULL;
		x->i++;
	}
	x->pwidth = ft_strlen(x->piece[0]);
}

static void		make_clean(t_filler *x)
{
	int		i;

	i = 1;
	while (x->fheight - i >= 0)
	{
		free(x->field[x->fheight - i]);
		free(x->intfield[x->fheight - i]);
		i++;
	}
	i = 1;
	while (x->pheight - i >= 0)
	{
		free(x->piece[x->pheight - i]);
		free(x->intpiece[x->pheight - i]);
		x->piece[i] = NULL;
		i++;
	}
}

static int		place_output(t_filler *x, int how)
{
	if (how == 1)
	{
		x->h_res = 0;
		x->w_res = 0;
	}
	ft_putnbr(x->h_res);
	ft_putchar(' ');
	ft_putnbr(x->w_res);
	ft_putchar('\n');
	return (0);
}

int				main(void)
{
	t_filler	x;
	char		*line;

	line = NULL;
	find_player(&x);
	while ((x.oper = get_next_line(0, &line)) > -1)
	{
		if (!ft_strncmp(line, "Plateau ", 8))
			x.oper2 = read_pole(&x, line);
		else if (!ft_strncmp(line, "Piece ", 6))
		{
			read_piece(&x, line);
			if (x.oper2 == 0)
				return (place_output(&x, 1));
			fill_numbers(&x);
			x.oper = placer_int(&x);
			place_output(&x, 0);
			make_clean(&x);
			if (x.oper == 0)
				return (0);
		}
		else
			ft_strdel(&line);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_okantovka.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 13:46:49 by student           #+#    #+#             */
/*   Updated: 2020/03/23 13:53:14 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		place_one(t_filler *x, int h, int w)
{
	if (h > 0)
		if (x->intfield[h - 1][w] == 0)
			x->intfield[h - 1][w] = 1;
	if (w > 0)
		if (x->intfield[h][w - 1] == 0)
			x->intfield[h][w - 1] = 1;
	if (h + 1 < x->fheight)
		if (x->intfield[h + 1][w] == 0)
			x->intfield[h + 1][w] = 1;
	if (w + 1 < x->fwidth)
		if (x->intfield[h][w + 1] == 0)
			x->intfield[h][w + 1] = 1;
}

void			okantovka(t_filler *x)
{
	int		h;
	int		w;

	h = 0;
	while (h < x->fheight)
	{
		w = 0;
		while (w < x->fwidth)
		{
			if (x->intfield[h][w] == x->int_opponent)
				place_one(x, h, w);
			w++;
		}
		h++;
	}
}

void			find_player(t_filler *x)
{
	char	*line;

	get_next_line(0, &line);
	x->player = line[10] - 48;
	ft_strdel(&line);
}

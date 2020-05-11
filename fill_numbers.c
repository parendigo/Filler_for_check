/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 11:10:18 by mlarraq           #+#    #+#             */
/*   Updated: 2020/03/23 13:31:53 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		make_field_int(t_filler *x)
{
	int		h;
	int		w;

	h = 0;
	while (h < x->fheight)
	{
		w = 0;
		if (!(x->intfield[h] = (int *)malloc(sizeof(int *) * (x->fwidth))))
			exit(0);
		while (w < x->fwidth)
		{
			if (x->field[h][w] == '.')
				x->intfield[h][w] = 0;
			else if (x->field[h][w] == 'O' || x->field[h][w] == 'o')
				x->intfield[h][w] = -1;
			else if (x->field[h][w] == 'X' || x->field[h][w] == 'x')
				x->intfield[h][w] = -2;
			w++;
		}
		h++;
	}
}

static void		place_the_rest(t_filler *x, int h, int w)
{
	int		nu;

	nu = 0;
	if (h > 0)
		if (x->intfield[h - 1][w] > 0)
			if (nu == 0 || x->intfield[h][w - 1] < nu)
				nu = x->intfield[h - 1][w];
	if (w > 0)
		if (x->intfield[h][w - 1] > 0)
			if (nu == 0 || x->intfield[h][w - 1] < nu)
				nu = x->intfield[h][w - 1];
	if (h + 1 < x->fheight)
		if (x->intfield[h + 1][w] > 0)
			if (nu == 0 || x->intfield[h][w - 1] < nu)
				nu = x->intfield[h + 1][w];
	if (w + 1 < x->fwidth)
		if (x->intfield[h][w + 1] > 0)
			if (nu == 0 || x->intfield[h][w - 1] < nu)
				nu = x->intfield[h][w + 1];
	nu = nu == 0 ? 0 : nu + 1;
	x->intfield[h][w] = nu;
}

static void		the_rest_numbers(t_filler *x, int *flag)
{
	int		h;
	int		w;
	int		count;

	h = 0;
	count = 0;
	while (h < x->fheight)
	{
		w = 0;
		while (w < x->fwidth)
		{
			if (x->intfield[h][w] == 0)
			{
				place_the_rest(x, h, w);
				count++;
			}
			w++;
		}
		w = 0;
		h++;
	}
	if (count == 0)
		*flag = 1;
}

static void		fill_piece_numbers(t_filler *x)
{
	int		h;
	int		w;

	h = 0;
	while (h < x->pheight)
	{
		w = 0;
		if (!(x->intpiece[h] = (int *)malloc(sizeof(int) * (x->fwidth))))
			exit(0);
		while (w < x->pwidth)
		{
			if (x->piece[h][w] == '.')
				x->intpiece[h][w] = 0;
			else
				x->intpiece[h][w] = x->int_my_char;
			w++;
		}
		h++;
	}
}

void			fill_numbers(t_filler *x)
{
	int		flag;
	int		kostil;

	flag = 0;
	kostil = 0;
	x->my_char = x->player == 1 ? 'O' : 'X';
	x->opponent = x->player == 1 ? 'X' : 'O';
	x->int_my_char = x->player == 1 ? -1 : -2;
	x->int_opponent = x->player == 1 ? -2 : -1;
	make_field_int(x);
	okantovka(x);
	while (flag == 0 && kostil < 100)
	{
		the_rest_numbers(x, &flag);
		kostil++;
	}
	fill_piece_numbers(x);
}

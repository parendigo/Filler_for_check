/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 15:50:38 by mlarraq           #+#    #+#             */
/*   Updated: 2020/03/23 13:38:21 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		step_conditions(t_filler *x, int h, int w)
{
	if (x->intpiece[x->h1][x->w1] == 0)
		x->w1 = x->w1 + 0;
	else if (x->intpiece[x->h1][x->w1] == x->int_my_char &&
			x->intfield[h + x->h1][w + x->w1] == x->int_opponent)
		return (0);
	else if (x->intpiece[x->h1][x->w1] == x->int_my_char &&
			x->intfield[h + x->h1][w + x->w1] == x->int_my_char)
		x->count++;
	else if (x->intfield[h + x->h1][w + x->w1] == 0)
	{
		x->summ = x->summ + (x->fheight * x->fwidth);
		x->co++;
	}
	else
	{
		x->summ = x->summ + x->intfield[h + x->h1][w + x->w1];
		x->co++;
	}
	return (1);
}

static int		result_conditions(t_filler *x, int h, int w)
{
	if (x->count > 1)
		return (0);
	if (x->summ_of_numbers == 0 && x->count == 1 && x->flag == 0)
	{
		x->flag = 1;
		x->summ_of_numbers = x->summ;
		x->count_cross = x->count;
		x->h_res = h;
		x->w_res = w;
	}
	else if (x->summ < x->summ_of_numbers && x->count == 1)
	{
		x->summ_of_numbers = x->summ;
		x->count_cross = x->count;
		x->h_res = h;
		x->w_res = w;
	}
	else
		return (0);
	return (1);
}

static int		try_to_place(t_filler *x, int h, int w)
{
	x->h1 = 0;
	x->count = 0;
	x->summ = 0;
	x->co = 0;
	while (x->h1 < x->pheight)
	{
		x->w1 = 0;
		while (x->w1 < x->pwidth)
		{
			if (step_conditions(x, h, w) == 0)
				return (0);
			x->w1++;
		}
		x->h1++;
	}
	x->summ = x->summ / x->co;
	if (result_conditions(x, h, w) == 0)
		return (0);
	return (1);
}

int				placer_int(t_filler *x)
{
	int		h;
	int		w;
	int		b;

	h = 0;
	b = 0;
	x->flag = 0;
	x->summ_of_numbers = 0;
	x->count_cross = 0;
	x->h_res = 0;
	x->w_res = 0;
	while (h < x->fheight - x->pheight + 1)
	{
		w = 0;
		while (w < x->fwidth - x->pwidth + 1)
		{
			if (try_to_place(x, h, w) == 1)
				b = 1;
			w++;
		}
		h++;
	}
	return (b);
}

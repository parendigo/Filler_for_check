/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_till.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 04:46:05 by mlarraq           #+#    #+#             */
/*   Updated: 2019/04/23 06:11:42 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_till(const char *str, const char c)
{
	const char *s;

	s = str;
	while (*s)
	{
		if (*s == c)
			return (s - str);
		++str;
	}
	return (0);
}

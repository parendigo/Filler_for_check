/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 00:13:03 by mlarraq           #+#    #+#             */
/*   Updated: 2019/04/23 06:57:44 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char *bla;

	bla = (unsigned char *)arr;
	while (n--)
	{
		if (*bla == (unsigned char)c)
			return (bla);
		if (n)
			bla++;
	}
	return (NULL);
}

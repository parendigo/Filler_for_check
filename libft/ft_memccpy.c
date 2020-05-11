/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 23:21:37 by mlarraq           #+#    #+#             */
/*   Updated: 2019/04/23 06:44:00 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *source, int c, size_t n)
{
	size_t			i;
	unsigned char	*src;
	unsigned char	*dest;

	i = 0;
	src = (unsigned char*)source;
	dest = (unsigned char*)d;
	while (i < n)
	{
		dest[i] = src[i];
		if (src[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}

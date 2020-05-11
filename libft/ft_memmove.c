/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 22:19:26 by mlarraq           #+#    #+#             */
/*   Updated: 2019/04/23 07:12:11 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *d, const void *source, size_t n)
{
	if (source <= d)
		while (n--)
			((unsigned char *)d)[n] = ((unsigned char *)source)[n];
	else
		ft_memcpy(d, source, n);
	return (d);
}

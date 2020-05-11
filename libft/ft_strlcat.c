/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 17:20:12 by mlarraq           #+#    #+#             */
/*   Updated: 2019/04/23 07:28:14 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t nb)
{
	size_t i;
	size_t b;
	size_t k;

	i = 0;
	b = ft_strlen(dest);
	k = ft_strlen(src);
	if (nb <= b)
		return (k + nb);
	while (*dest)
		dest++;
	while (src[i] && i < (nb - b - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (b + k);
}

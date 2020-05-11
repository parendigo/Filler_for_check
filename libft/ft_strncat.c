/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 03:06:06 by mlarraq           #+#    #+#             */
/*   Updated: 2019/04/24 07:55:18 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *d, const char *append, size_t n)
{
	size_t i;
	size_t b;

	i = 0;
	b = 0;
	while (d[i] != '\0')
		i++;
	while (((char*)append)[b] != '\0' && b < n)
		d[i++] = ((char*)append)[b++];
	d[i] = '\0';
	return (d);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:04:23 by mlarraq           #+#    #+#             */
/*   Updated: 2019/06/14 18:07:13 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmdup(const char *s, size_t start, size_t finish)
{
	size_t	i;
	size_t	a;
	char	*src;

	i = 0;
	a = start;
	while (s[start] && start < finish)
		start++;
	if (!(src = (char*)malloc(sizeof(*src) * (start - a + 1))))
		return (NULL);
	while (a < start)
		src[i++] = s[a++];
	src[i] = '\0';
	return (src);
}

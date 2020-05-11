/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 07:41:34 by mlarraq           #+#    #+#             */
/*   Updated: 2019/04/23 07:28:03 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*src;
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(src = (char*)malloc(sizeof(char)
					* (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (a < ft_strlen(s1))
	{
		src[a] = s1[a];
		a++;
	}
	while (a < ft_strlen(s1) + ft_strlen(s2))
		src[a++] = s2[b++];
	src[a] = '\0';
	return (src);
}

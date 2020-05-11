/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 04:43:10 by mlarraq           #+#    #+#             */
/*   Updated: 2019/04/23 07:36:44 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t i;
	size_t b;

	i = 0;
	if (((char*)find)[i] == '\0')
		return (((char*)str) + i);
	while (((char*)str)[i] != '\0' && i < len)
	{
		b = 0;
		while ((((char*)str)[i + b] == ((char*)find)[b]
				|| ((char*)find)[b] == '\0') && i + b <= len)
		{
			if (((char*)find)[b] == '\0')
				return (((char*)str) + i);
			b++;
		}
		i++;
	}
	return (0);
}

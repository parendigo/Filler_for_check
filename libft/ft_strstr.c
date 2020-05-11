/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:59:34 by mlarraq           #+#    #+#             */
/*   Updated: 2019/04/23 07:51:29 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	size_t i;
	size_t b;

	i = 0;
	if (to_find[i] == '\0')
		return ((char *)str + i);
	while (str[i] != '\0')
	{
		b = 0;
		while (str[i + b] == to_find[b])
		{
			if (to_find[b + 1] == '\0')
				return ((char *)str + i);
			b++;
		}
		i++;
	}
	return (0);
}

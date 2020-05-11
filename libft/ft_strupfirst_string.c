/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 10:52:51 by mlarraq           #+#    #+#             */
/*   Updated: 2019/04/23 07:54:31 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strupfirst_string(const char *s)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (!*s)
		return (NULL);
	dst = ft_strdup(s);
	if (dst == NULL)
		return (NULL);
	while (dst[i])
	{
		if (dst[i] >= 'a' && dst[i] <= 'z' && ft_isalpha(dst[i - 1]) == 0)
			dst[i] = dst[i] - 32;
		else if (dst[i] >= 'A' && dst[i] <= 'Z' && ft_isalpha(dst[i - 1]) == 1)
			dst[i] = dst[i] + 32;
		i++;
	}
	return (dst);
}

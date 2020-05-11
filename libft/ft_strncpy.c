/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 02:36:26 by mlarraq           #+#    #+#             */
/*   Updated: 2019/04/23 07:33:02 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *d, const char *source, size_t n)
{
	int i;

	i = 0;
	while (source[i] && i < (int)n)
	{
		d[i] = (char)source[i];
		i++;
	}
	while (i < (int)n)
	{
		d[i] = '\0';
		i++;
	}
	return (d);
}

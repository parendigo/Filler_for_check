/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 02:12:19 by mlarraq           #+#    #+#             */
/*   Updated: 2019/04/23 07:23:59 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *destination, const char *source)
{
	size_t i;

	i = 0;
	while (((char*)source)[i] != '\0')
	{
		destination[i] = ((char*)source)[i];
		i++;
	}
	destination[i] = '\0';
	return (destination);
}

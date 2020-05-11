/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 17:20:12 by mlarraq           #+#    #+#             */
/*   Updated: 2019/04/23 07:21:34 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *destination, const char *append)
{
	int i;
	int b;

	i = 0;
	b = 0;
	while (destination[i] != '\0')
		i++;
	while (((char*)append)[b] != '\0')
		destination[i++] = ((char*)append)[b++];
	destination[i] = '\0';
	return (destination);
}

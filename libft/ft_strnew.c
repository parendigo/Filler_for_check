/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 06:11:46 by mlarraq           #+#    #+#             */
/*   Updated: 2019/04/24 07:55:38 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*src;

	if (size + 1 < size)
		return (NULL);
	if (!(src = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(src, '\0', size + 1);
	return (src);
}

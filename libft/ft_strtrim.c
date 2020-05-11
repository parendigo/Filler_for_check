/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 12:56:31 by mlarraq           #+#    #+#             */
/*   Updated: 2019/04/23 07:53:43 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	start(char const *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	return (i);
}

static int	finish(char const *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	i--;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i != 0)
		i--;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	int		a;
	int		min;
	int		max;
	char	*src;

	a = 0;
	if (!s)
		return (NULL);
	min = start(s);
	max = finish(s);
	if (min > max)
	{
		if (!(src = (char*)malloc(sizeof(*src) * 1)))
			return (NULL);
	}
	else if (!(src = (char*)malloc(sizeof(*src) * (max - min + 2))))
		return (NULL);
	while (min <= max)
	{
		src[a] = s[min];
		a++;
		min++;
	}
	src[a] = '\0';
	return (src);
}

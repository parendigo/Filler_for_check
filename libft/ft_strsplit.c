/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:00:10 by mlarraq           #+#    #+#             */
/*   Updated: 2019/04/23 07:51:20 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(char const *s, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb++;
			while (s[i] == c)
				i++;
		}
		else if (s[i] && s[i] != c)
			i++;
	}
	if (s[i - 1] != c && i != 0)
		nb++;
	return (nb);
}

static int		count_size(char const *s, int i, char c)
{
	int	nb;

	nb = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		nb++;
	}
	return (nb);
}

static char		*ft_mall(char const *s, int *a, char c)
{
	int		b;
	char	*dst;

	if (!(dst = (char*)malloc(sizeof(char) * (count_size(s, *a, c) + 1))))
		return (NULL);
	b = 0;
	while (s[*a] != c && s[*a])
	{
		dst[b] = s[*a];
		b++;
		*a += 1;
	}
	dst[b] = '\0';
	while (s[*a] && s[*a] == c)
		*a += 1;
	return (dst);
}

static void		ft_delall(char **d, int i)
{
	while (--i > 0)
		free(d[i]);
	free(d[i]);
	free(d);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**d;
	int		i;
	int		a;

	i = 0;
	a = 0;
	if (!s || !c)
		return (NULL);
	if (!(d = (char**)malloc(sizeof(char**) * (count_words(s, c) + 1))))
		return (NULL);
	while (s[a] && s[a] == c)
		a++;
	while (i < count_words(s, c) && s[a])
	{
		if ((d[i] = ft_mall(s, &a, c)) == NULL)
		{
			ft_delall(d, i);
			return (NULL);
		}
		i++;
	}
	d[i] = NULL;
	return (d);
}

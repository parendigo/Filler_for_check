/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 09:16:37 by mlarraq           #+#    #+#             */
/*   Updated: 2019/04/23 06:13:49 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define WORDS (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z')

int		ft_count_words(const char *s)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	if (!*s)
		return (0);
	while (!WORDS)
		i++;
	while (s[i])
	{
		if (WORDS)
		{
			count++;
			while (WORDS)
				i++;
		}
		else
			i++;
	}
	return (count);
}

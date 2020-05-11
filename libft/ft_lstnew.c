/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 20:14:10 by mlarraq           #+#    #+#             */
/*   Updated: 2019/04/24 07:08:57 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*a;

	if (!(a = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		a->content = NULL;
		a->content_size = 0;
	}
	else
	{
		if (!(a->content = ft_strsub(content, 0, content_size)))
			return (NULL);
		a->content_size = content_size;
	}
	a->next = NULL;
	return (a);
}

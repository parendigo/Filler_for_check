/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 20:15:58 by mlarraq           #+#    #+#             */
/*   Updated: 2019/04/21 05:56:39 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*i;

	if (alst && del)
	{
		while (*alst)
		{
			i = (*alst)->next;
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = i;
		}
	}
}

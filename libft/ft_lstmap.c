/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 01:42:36 by mlarraq           #+#    #+#             */
/*   Updated: 2019/04/24 07:30:34 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(t_list **alst)
{
	t_list	*i;

	i = (*alst);
	while (*alst)
	{
		i = (*alst)->next;
		free((*alst)->content);
		free(*alst);
		*alst = i;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*dest;
	t_list	*str;
	t_list	*elem;

	if (!lst || !f)
		return (NULL);
	elem = f(lst);
	if (!(dest = ft_lstnew(elem->content, elem->content_size)))
		return (NULL);
	lst = lst->next;
	str = dest;
	while (lst)
	{
		elem = f(lst);
		if (!(dest->next = ft_lstnew(elem->content, elem->content_size)))
		{
			ft_free(&str);
			return (NULL);
		}
		dest = dest->next;
		lst = lst->next;
	}
	return (str);
}

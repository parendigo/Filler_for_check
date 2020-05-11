/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 18:12:08 by mlarraq           #+#    #+#             */
/*   Updated: 2020/03/23 13:57:42 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrejoin(char *s1, char *s2)
{
	char	*src;
	ssize_t	count1;
	ssize_t	count2;

	count1 = ft_strlen(s1);
	count2 = ft_strlen(s2);
	if (!(src = (char*)malloc(sizeof(*src) * (count1 + count2 + 1))))
		return (NULL);
	src[count1 + count2] = '\0';
	while (--count2 >= 0)
		src[count1 + count2] = s2[count2];
	while (--count1 >= 0)
		src[count1] = s1[count1];
	free(s1);
	return (src);
}

char			*ft_strfromstart(const char *s, size_t start)
{
	size_t	i;
	size_t	a;
	char	*src;

	i = 0;
	a = ft_strlen(s);
	if (!(src = (char*)malloc(sizeof(*src) * (a - start + 1))))
		return (NULL);
	while (start < a)
		src[i++] = s[start++];
	src[i] = '\0';
	return (src);
}

char			*cool_function(char ***line, char **text)
{
	char		*s;
	size_t		i;

	i = 0;
	while ((*text)[i] != '\n' && (*text)[i] != '\0')
		i++;
	**line = ft_strmdup(*text, 0, i);
	i++;
	s = ft_strfromstart(*text, i);
	free(*text);
	return (s);
}

int				strcmpcustom(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char	*text[10240];
	char		buffer[BUFF_SIZE + 1];
	ssize_t		count;

	if (fd > 10240 || line == NULL || read(fd, NULL, 0) < 0)
		return (-1);
	else if (strcmpcustom(text[fd]) == 0)
		while ((count = read(fd, buffer, BUFF_SIZE)) > 0)
		{
			buffer[count] = '\0';
			text[fd] = ft_strrejoin(text[fd], buffer);
			if (strcmpcustom(text[fd]) == 1)
			{
				text[fd] = cool_function(&line, &text[fd]);
				return (1);
			}
		}
	if (!text[fd])
		text[fd] = ft_strnew(1);
	count = (text[fd][0] != '\0' ? 1 : 0);
	text[fd] = cool_function(&line, &text[fd]);
	if (text[fd][0] == '\0')
		ft_strdel(&text[fd]);
	return (count == 1 ? 1 : 0);
}

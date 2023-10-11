/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:15:58 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/10/05 16:16:00 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_init(t_link *buff, int *i, size_t *x)
{
	*x = 0;
	*i = BUFFER_SIZE;
	if (!buff->buffer)
		buff->len = 0;
}

char	*ft_return(t_link *buff, size_t len)
{
	char	*str_b;
	char	*str_r;
	char	*str;

	str_r = (char *)malloc(sizeof(char) * (len + 1));
	if (!str_r)
		return (free(buff->buffer), buff->buffer = NULL, NULL);
	str_b = (char *)malloc(sizeof(char) * (buff->len - len + 1));
	if (!str_b)
		return (free(buff->buffer), free(str_r), buff->buffer = NULL, NULL);
	ft_strlcpy(str_r, buff->buffer, len +1);
	str = buff->buffer;
	str += len ;
	ft_strlcpy(str_b, str, buff->len - len + 1);
	free (buff->buffer);
	buff->buffer = NULL;
	if (*str_b == '\0')
		free(str_b);
	else
	{
		buff->buffer = str_b;
		buff->len -= len;
	}
	return (str_r);
}

char	*ft_readfail(t_link *buff, int i)
{
	if (i < 0)
	{
		free(buff->buffer);
		buff->buffer = NULL;
		return (NULL);
	}
	if (i == 0 && buff->buffer)
	{
		if (*buff->buffer == '\0')
		{
			free(buff->buffer);
			buff->buffer = NULL;
			return (NULL);
		}
		return (ft_free(buff));
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_link	buff;
	char			*new;
	int				i;
	size_t			x;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_init(&buff, &i, &x);
	new = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!new)
		return (free(buff.buffer), buff.buffer = NULL, NULL);
	while (i != 0)
	{
		x = new_line(&buff);
		if (x - 1 < buff.len)
			return (free(new), ft_return(&buff, x));
		i = read(fd, new, BUFFER_SIZE);
		if (i <= 0)
			return (free(new), ft_readfail(&buff, i));
		if (i != 0)
			buff.buffer = ft_strjoin(&buff, new, &i);
	}
	return (free(buff.buffer), buff.buffer = NULL, free(new), NULL);
}

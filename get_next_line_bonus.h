/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:20:50 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/10/05 16:20:52 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_list{
	size_t	len;
	char	*buffer;
}	t_link;

char	*get_next_line(int fd);
char	*ft_return(t_link *buff, size_t len);
char	*ft_readfail(t_link *buff, int i);

size_t	new_line(t_link *buff);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_free(t_link *buff);
char	*ft_strjoin(t_link *buff, char *s2, int i);

#endif

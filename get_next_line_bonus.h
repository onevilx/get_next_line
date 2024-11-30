/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:22:06 by yaboukir          #+#    #+#             */
/*   Updated: 2024/11/29 22:03:23 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // it is forbidden to use this lib, remove it later.
# include <fcntl.h> // it is forbidden to use this lib, remove it later.

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_SETSIZE
#  define FD_SETSIZE 1024
# endif

char	*get_next_line(int fd);
char	*strdup(const char *s1);
char	*ft_strjoin(char *s1, char const *s2);
int		ft_strchr(const char *str, char c);
size_t	ft_strlen(const char *str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_header.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 14:12:30 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/25 04:36:07 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_HEADER_H
# define BONUS_HEADER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*my_strdup(char *s);
char	*substr(char *str, int index);





# ifndef MAX_FD
#  ifdef OPEN_MAX
#   define MAX_FD OPEN_MAX
#  else
#   define MAX_FD 1024
#  endif
# endif

#endif

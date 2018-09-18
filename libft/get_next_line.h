/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 12:33:30 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/18 09:02:33 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE	1024
# define SPLIT		'\n'
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int					get_next_line(const int fd, char **line);

#endif

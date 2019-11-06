/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinguyen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:43:47 by vinguyen          #+#    #+#             */
/*   Updated: 2019/11/05 14:44:38 by vinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# define BUFF_SIZE 8 //macro, altered by the reviewer
# define MAX_FD 256 //macro, ulimi-n to find the max file descriptors

# include <stdlib.h> //malloc,free
# include <unistd.h> //write, read
# include <stdio.h> //printf
# include <fcntl.h> //O_RDONLY

int get_next_line(const int fd, char **line); //prototype for get_next_line

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinguyen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:43:21 by vinguyen          #+#    #+#             */
/*   Updated: 2019/11/05 14:43:42 by vinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

int get_next_line(const int fd, char **line)
{
	static  char *fds[BUFF_SIZE];  //An array of pointers to the str the fds contain
	ssize_t	bytes_rd;
	char *buf;
	// char *blank = "";
	char *nwl_loc;
	char *tmp;
	int rd = 0;
	if (fd < 0 || !line || fd > MAX_FD)
		return (-1);
	if (fds[fd] == NULL)
		fds[fd] = "";
	if ((nwl_loc = ft_strchr(fds[fd], '\n')))
	{
		*line = ft_strsub(fds[fd], 0, nwl_loc - fds[fd]); //finds the substr and assign to line
		tmp = ft_strsub(fds[fd], ft_strlen(*line) + 1, ft_strlen(nwl_loc + 1)); //keeps track of the remaining string
		free (fds[fd]);
		fds[fd] = tmp;
		return 1;
	}
	buf = ft_memalloc(BUFF_SIZE);
	while ((bytes_rd = read(fd, buf, BUFF_SIZE)) > 0) //While able to read the file and there is no new  line in the fds[fd]
	{
		char *tmp = ft_strjoin (fds[fd], buf); //Join my buf with the remaining string in fds
		free (buf); 
		buf = ft_memalloc(BUFF_SIZE);
		fds[fd] = tmp;
		if ((nwl_loc = ft_strchr(fds[fd], '\n')))
		{
			*line = ft_strsub(fds[fd], 0, nwl_loc - fds[fd]); //finds the substr and assign to line
			fds[fd] = ft_strsub(fds[fd], ft_strlen(*line) + 1, ft_strlen(nwl_loc + 1)); //keeps track of the remaining string
			return 1;
		}
		rd = 1;
	}
	if (rd == 1)
	{
		*line = fds[fd];
		return (1);
	}
	if (bytes_rd == -1) //If there was an error reading
		return (-1);
	free(fds[fd]);
	return (0); //File read successfully
}

#ifdef MAIN2
int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	char		*filename;
	int			errors;

	filename = "gnl1_1.txt";
	fd = open(filename, O_RDONLY);
	if (fd > 2)
	{
		count_lines = 0;
		errors = 0;
		line = NULL;
		// // printf("%d\n", get_next_line(fd, &line));
		// // printf("%d\n", get_next_line(fd, &line));
		// // printf("%d\n", get_next_line(fd, &line));
		// printf("%zu\n", read(fd, line, BUFF_SIZE));
		// printf("%zu\n", read(fd, line, BUFF_SIZE));
		// printf("%zu\n", read(fd, line, BUFF_SIZE));
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			// if (count_lines == 0 && ft_strcmp(line, "1234567") != 0)
			// 	errors++;
			count_lines++;
			// if (count_lines > 50)
			// 	break;
		}
		printf("%d\n", count_lines);
	}
	// 	close(fd);
	// 	if (count_lines != 1)
	// 		printf("-> must have returned '1' once instead of %d time(s)\n", count_lines);
	// 	if (errors > 0)
	// 		printf("-> must have read \"1234567\" instead of \"%s\"\n", line);
	// 	if (count_lines == 1 && errors == 0)
	// 		printf("OK\n");
	// }
	// else
	// 	printf("An error occured while opening file %s\n", filename);
	return (0);
}
#endif

#ifdef MAIN
// # define FN "/nfs/2019/v/vinguyen/42FileChecker/srcs/gnl/gnl7_1.txt"
# define FN "gnl1_1.txt"
int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	char		*filename;
	int			errors;
	
	fd = open(FN, O_RDONLY);
	if (fd > 2)
	{
		count_lines = 0;
		errors = 0;
		line = ft_memalloc(BUFF_SIZE);
		// printf("%zd\n", read(fd, line, BUFF_SIZE));
		// printf("%zd", read(fd, line, BUFF_SIZE));
		// printf("%d", get_next_line(fd, &line));
		// printf("%d", get_next_line(fd, &line));
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			count_lines++;
			printf("%s\n", line);
		}
		printf("%d", count_lines);
	}
	close(fd);
	return (0);
}
#endif
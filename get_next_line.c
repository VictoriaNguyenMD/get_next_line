/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinguyen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:43:21 by vinguyen          #+#    #+#             */
/*   Updated: 2019/11/09 16:36:19 by vinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

int		read_new_line(char **fds, int fd, char **line)
{
	char	*tmp;
	char *nwl_loc;

	if ((nwl_loc = ft_strchr(fds[fd], '\n')))
	{
		tmp = fds[fd];
		*line = ft_strsub(fds[fd], 0, nwl_loc - fds[fd]);
		fds[fd] = ft_strsub(fds[fd],
			ft_strlen(*line) + 1, ft_strlen(nwl_loc + 1));
		free(tmp);
		return (1);
	}
	return (0);
}

void	string_join_free(char **fds, int fd, char *buf)
{
	char	*tmp;

	tmp = fds[fd];
	fds[fd] = ft_strjoin(fds[fd], buf);
	free(tmp);
}

int		get_next_line(const int fd, char **line)
{
	static	char	*fds[MAX_FD];
	ssize_t			bytes_rd;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;

	if (fd < 0 || !line || fd > MAX_FD || 
			BUFF_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	fds[fd] = (fds[fd] == NULL) ? ft_strnew(1) : fds[fd];
	if (read_new_line(fds, fd, line) == 1)
		return (1);
	while ((bytes_rd = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[bytes_rd] = '\0';
		string_join_free(fds, fd, buf);
		if (read_new_line(fds, fd, line) == 1) 
			return (1);
	}
	if (bytes_rd == 0 && (fds[fd][0] == '\0'))
		return (0);
	tmp = fds[fd];
	*line = ft_strdup(fds[fd]);
	fds[fd] = ft_strnew(1);
	free(tmp);
	return (1);
}

#ifdef TEST
#include <stdio.h>
#include <fcntl.h>
int	main(int argc )
{
	char *line;
	int fd = open("test00.txt", O_RDONLY);
	int fd2 = open("test01.txt", O_RDONLY);
	int fd3 = open("test02.txt", O_RDONLY);
	int fd4 = open("test03.txt", O_RDONLY);
	int fd5 = open("test04.txt", O_RDONLY);
	int fd6 = open("test05.txt", O_RDONLY);
	int fd7 = open("test06.txt", O_RDONLY);
	int fd8 = open("test07.txt", O_RDONLY);
	int fd9 = open("test08.txt", O_RDONLY);
	int fd10 = open("test09.txt", O_RDONLY);
	int fd11 = open("test10.txt", O_RDONLY);
	// printf("%d\n", fd1);
	// printf("%d\n", fd2);
	// get_next_line(fd1, &line);
	// printf("%s\n", line);
	// free(line);
	// get_next_line(fd2, &line);
	// printf("%s\n", line);
	// free(line);
	// get_next_line(fd1, &line);
	// printf("%s\n", line);
	// free(line);
	// get_next_line(fd2, &line);
	// printf("%s\n", line);
	// free(line);

	// while(get_next_line(fd1, &line) > 0)
	// {
	// 	printf("%s\n", line);
	// 	get_next_line(fd2, &line);
	// 	printf("%s\n", line);
	// 	get_next_line(fd3, &line);
	// 	printf("%s\n", line);
	// 	get_next_line(fd4, &line);
	// 	printf("%s\n", line);
	// 	get_next_line(fd5, &line);
	// 	printf("%s\n", line);
	// 	get_next_line(fd6, &line);
	// 	printf("%s\n", line);
	// 	get_next_line(fd7, &line);
	// 	printf("%s\n", line);
	// 	get_next_line(fd8, &line);
	// 	printf("%s\n", line);
	// 	get_next_line(fd9, &line);
	// 	printf("%s\n", line);
	// 	get_next_line(fd10, &line);
	// 	printf("%s\n", line);
	// 	get_next_line(fd11, &line);
	// 	printf("%s\n", line);
	// 	// printf("%d\n", get_next_line(777, &line));
	// 	// printf("%s\n", line);
	// }
	while(get_next_line(fd, &line) == 1)
	{
		printf("%s\n", line);
	}
	// const int check = 3;
	// static	char	*d_ch[MAX_FD] = {"qwe"};
	// if (check[d_ch][0])
	// 	printf("%d\n", 1);
	return (0);
}
#endif

#ifdef TEST2
#include <stdio.h>
#include <fcntl.h>
int                main(int argc, char **argv)
{
    int            i;
    int            fd1;
    int            fd2;
    char        *line1;
    char        *line2;
    if (argc > 1 && argc <= 3)
    {
        i = 0;
        fd1 = open(argv[1], O_RDONLY);
        fd2 = open(argv[2], O_RDONLY);
        while ((get_next_line(fd1, &line1)) == 1)
        {
            ft_putstr(line1);
            ft_putchar('\n');
        }
        close(fd1);
        while ((get_next_line(fd2, &line2)) == 1)
        {
            ft_putstr(line2);
            ft_putchar('\n');
        }
        close(fd2);
    }
    return (0);
#endif
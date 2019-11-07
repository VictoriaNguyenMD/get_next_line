/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinguyen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 00:42:06 by vinguyen          #+#    #+#             */
/*   Updated: 2019/11/06 19:28:23 by vinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Locates the first occurence of c in a string. The null character \0
**	is part of the string
** Input: const char s, int c
** Return:
**		ptr to located char
**		NULL if not in the string
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (1)
	{
		if (s[0] == c)
			return ((char *)s);
		if (s[0] == '\0')
			return (NULL);
		if (s[1] == c)
			return ((char *)(s + 1));
		if (s[1] == '\0')
			return (NULL);
		if (s[2] == c)
			return ((char *)(s + 2));
		if (s[2] == '\0')
			return (NULL);
		if (s[3] == c)
			return ((char *)(s + 3));
		if (s[3] == '\0')
			return (NULL);
		if (s[4] == c)
			return ((char *)(s + 4));
		if (s[4] == '\0')
			return (NULL);
		s += 5;
	}
}

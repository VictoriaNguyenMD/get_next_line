/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinguyen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 00:00:19 by vinguyen          #+#    #+#             */
/*   Updated: 2019/10/11 00:00:21 by vinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Allocates using malloc and returns fresh string ending with '\0'
**	Result of the concat of s1 and s2. If alloc fails, returns NULL
** Param: prefix string, suffix string
** Return: new string
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*result;
	char			*head;
	unsigned int	total_len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(sizeof(*result) * (total_len + 1));
	if (result == NULL)
		return (NULL);
	head = result;
	while (*s1)
	{
		*result = *s1;
		result++;
		s1++;
	}
	while (*s2)
	{
		*result = *s2;
		result++;
		s2++;
	}
	*result = '\0';
	return (head);
}

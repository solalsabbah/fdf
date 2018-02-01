/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 18:58:38 by ssabbah           #+#    #+#             */
/*   Updated: 2018/02/01 18:58:40 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strfjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	a;
	size_t	b;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	if ((str = (char *)ft_memalloc(sizeof(*str) * (a + b + 1))) == NULL)
		return (NULL);
	while (i < a)
	{
		str[i] = s1[i];
		i++;
	}
	while (i < a + b)
	{
		str[i] = s2[i - a];
		i++;
	}
	free(s1);
	free(s2);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:06:30 by fruiz-ca          #+#    #+#             */
/*   Updated: 2022/05/13 12:10:36 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return (&str[ft_strlen(s)]);
	while (str[i])
	{
		if (str[i] == (char)c)
			return (&str[i]);
		str++;
	}
	return (0);
}

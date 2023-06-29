/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfelida <mfelida@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:58:03 by mfelida           #+#    #+#             */
/*   Updated: 2023/06/28 16:47:37 by mfelida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*dest;

	len = ft_strlen(src);
	dest = (char *) malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL); 
	i = 0;
	while (i < len)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

int	ft_char_in_str(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	ft_unique_chars(char *str)
{
	int	i;

	while (*str && str[1])
	{
		i = 1;
		while (str[i])
		{
			if (*str == str[i])
				return (0);
			i++;
		}
		str++;
	}
	return (1);
}

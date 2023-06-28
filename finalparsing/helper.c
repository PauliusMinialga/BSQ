/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 10:12:17 by pminialg      #+#    #+#                 */
/*   Updated: 2023/06/28 10:12:18 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_atoi(char *str)
{
	unsigned int	nb;
	int				sign;
	int				i;

	i = 0;
	sign = 0;
	nb = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += str[i++] - '0';
	}
	if (sign % 2 == 1)
		return (nb * -1);
	return (nb);
}

char	*ft_strndup(char *str, size_t n)
{
	size_t	length;
	size_t	i;
	char	*dup;

	i = 0;
	length = 0;
	while (str[length] != '\0' && length < n)
	{
		length++;
	}
	dup = (char *)malloc((length + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	while (i < length)
	{
		dup[i] = str[i];
		i++;
	}
	return (dup);
}

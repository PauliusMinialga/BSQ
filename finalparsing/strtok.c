/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strtok.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 12:36:56 by pminialg      #+#    #+#                 */
/*   Updated: 2023/06/28 13:53:44 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strtok(char *str, char *delim)
{
	static char	*next_token = NULL;
	char		*end_of_str = NULL;
	char		*token;
	int			is_delimiter;
	size_t		i;

	if (str != NULL)
	{
		next_token = str;
		end_of_str = str + ft_strlen(str);
	}
	else if (next_token == NULL || *next_token == '\0')
	{
		return (NULL);
	}
	token = next_token;
	while (next_token < end_of_str)
	{
		is_delimiter = 0;
		i = 0;
		while (delim[i] != '\0')
		{
			if (*next_token == delim[i])
			{
				is_delimiter = 1;
				break ;
			}
			i++;
		}
		if (is_delimiter)
		{
			*next_token = '\0';
			next_token++;
			return (token);
		}
		next_token++;
	}
	next_token = NULL;
	return (token);
}

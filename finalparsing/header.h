/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   header.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 10:12:49 by pminialg      #+#    #+#                 */
/*   Updated: 2023/06/28 17:20:51 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# define MAX_SIZE 1500

typedef struct {
    char *next_token;
    char *end_of_str;
} Tokenizer;

char	*ft_strcpy(char *dest, char *src);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
char	*ft_strndup(char *str, size_t n);
char	*ft_strtok(char *str, char *delim);
void	split_the_array(const char *original_array, int length, int num_rows, int num_cols, char ***splitarray);
void	parse_file(char *file);
int		main(int argc, char *argv[]);
char	*my_strchr(const char *str, int ch);
int		open_file(char *file);
ssize_t	read_file(int openfile, char *buffer, size_t size);
int		parse_first_line(char *buffer, int *num, char *chars);
char	**parse_lines(char *buffer, int num);
void	modify_array(char **splitarray, int num_rows, int num_cols, char *chars);
void	free_memory(char **data, int num_rows, char **splitarray);
#endif
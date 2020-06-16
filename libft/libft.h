/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 13:49:27 by lharris           #+#    #+#             */
/*   Updated: 2018/08/13 12:17:53 by lharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# define BUFF_SIZE 1028

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_memalloc(size_t size);
void	*ft_memset(void *str, int c, size_t n);
char	*ft_strcat(char *s1, const char *s2);
void	ft_strclr(char *s);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strnew(size_t size);
char	**ft_strsplit(char const *s, char c);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
int		get_next_line(const int fd, char **line);

#endif
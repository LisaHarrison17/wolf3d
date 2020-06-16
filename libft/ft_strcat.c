/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:40:14 by lharris           #+#    #+#             */
/*   Updated: 2018/09/17 14:33:22 by lharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char *first;

	first = s1;
	while (*s1)
	{
		s1++;
	}
	while (*s2)
	{
		*s1++ = *s2++;
	}
	*s1 = '\0';
	return (first);
}
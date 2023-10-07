/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <eej-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 11:15:52 by eej-jama          #+#    #+#             */
/*   Updated: 2022/10/15 11:16:46 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(char const *s1, char const *set)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s1[i] && set[j])
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
			continue ;
		}
		j++;
	}
	return (i);
}

static int	ft_end(char const *s1, char const *set, int i)
{
	int	len;
	int	j;

	j = 0;
	len = ft_strlen(s1) - 1;
	while (len > i && set[j])
	{
		if (s1[len] == set[j])
		{
			len--;
			j = 0;
			continue ;
		}
		j++;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*ptr;

	len = ft_strlen(s1) - 1;
	i = ft_start(s1, set);
	len = ft_end(s1, set, i);
	ptr = ft_substr(s1, i, len - i + 1);
	free((void *)s1);
	return (ptr);
}

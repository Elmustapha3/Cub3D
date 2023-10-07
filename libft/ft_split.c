/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:33:32 by eej-jama          #+#    #+#             */
/*   Updated: 2023/09/02 17:53:58 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	count_word(char const *s, char c)
{
	int	i;
	int	len;
	int	a;

	i = 0;
	len = 0;
	a = 1;
	while (s[i])
	{
		if (s[i] != c && a)
		{
			a = 0;
			len++;
		}
		if (s[i] == c)
			a = 1;
		i++;
	}
	return (len);
}

static int	ft_lencount(char const *s, char c, int *i)
{
	int	len;

	len = 0;
	while (s[*i])
	{
		if (s[*i] == c)
		{
			break ;
		}
		(*i)++;
		len++;
	}
	return (len);
}

static void	*freemove(char	***ptr, int d)
{
	char	**a;

	a = *ptr;
	if (!a[d])
	{
		while (d >= 0)
		{
			free(a[d]);
			d--;
		}
		free(a);
		return (0);
	}
	return ((void *)1);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		d;
	char	**ptr;

	i = 0;
	d = 0;
	if (!s)
		return (NULL);
	ptr = malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		ptr[d] = ft_substr(s, i, ft_lencount(s, c, &i));
		if (!freemove(&ptr, d))
			return (NULL);
		d++;
	}
	ptr[d] = NULL;
	return (ptr);
}

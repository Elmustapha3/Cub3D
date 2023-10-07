/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:04:16 by gloukas           #+#    #+#             */
/*   Updated: 2023/02/05 21:37:12 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_add(int fd, char *save)
{
	char	*buff;
	int		nb;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!ft_strchr(save, '\n'))
	{
		nb = read(fd, buff, BUFFER_SIZE);
		if (nb == -1)
			return (free(buff), free(save), NULL);
		if (nb == 0)
			break ;
		buff[nb] = '\0';
		save = ft_strjoin_free(save, buff);
	}
	free(buff);
	return (save);
}

char	*ft_ext_line(char *save)
{
	int		i;
	char	*s;

	i = 0;
	if (!save[i])
		return (NULL);
	i = ft_strlen_new(save);
	if (save[i] == '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		s[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		s[i] = save[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_clean(char *save)
{
	int		i;
	int		c;
	char	*s;

	i = ft_strlen_new(save);
	if (!save[i] || !save[i + 1])
		return (free(save), NULL);
	s = (char *)malloc(sizeof(char) * (ft_strlen(save) - i));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (save[i])
		s[c++] = save[i++];
	s[c] = '\0';
	free(save);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_read_add(fd, save);
	if (!save)
		return (NULL);
	line = ft_ext_line(save);
	save = ft_clean(save);
	return (line);
}

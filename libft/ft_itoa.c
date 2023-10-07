/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:35:08 by eej-jama          #+#    #+#             */
/*   Updated: 2023/08/05 15:12:33 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_chiffre(long nbr)
{
	int	len;

	len = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		len++;
	}
	while (nbr > 9)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int c)
{
	int		len;
	int		i;
	long	t;
	char	*temp;

	i = 1;
	t = (long)c;
	len = nbr_chiffre(t);
	temp = malloc(len + 1);
	if (!temp)
		return (NULL);
	temp[len] = '\0';
	if (c < 0)
		t *= -1;
	while (i <= len)
	{
		temp[len - i++] = t % 10 + 48;
		t /= 10;
	}
	if (c < 0)
		temp[0] = '-';
	return (temp);
}

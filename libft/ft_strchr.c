/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:08:20 by gnyssens          #+#    #+#             */
/*   Updated: 2024/04/17 15:13:05 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if ((char) c == str[i])
			return ((char *)str + i);
		i++;
	}
	if ((char) c == 0 && str[i] == 0)
		return ((char *)str + i);
	return (0);
}

/*
int main (void)
{
	printf("%s\n", ft_strchr("teste", 'e'));

	return 0;
}
*/

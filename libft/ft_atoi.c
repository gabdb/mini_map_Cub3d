/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:49:26 by gnyssens          #+#    #+#             */
/*   Updated: 2024/04/22 16:35:18 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		sign;
	long	res;
	long	buff;

	sign = 1;
	res = 0;
	buff = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= (-1);
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str++ - '0';
		if (buff > res && sign > 0)
			return (-1);
		else if (buff > res && sign < 0)
			return (0);
		buff = res;
	}
	return ((int) sign * res);
}


int main(void)
{
	const char string[] = " \t	\r +123456{ }|098juik  ";
	int result = ft_atoi(string);

	printf("Mon atoi : %d\nLe vrai atoi : %d", result, atoi(string));

	return 0;
}

